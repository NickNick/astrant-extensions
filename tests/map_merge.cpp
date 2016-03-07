#include <catch.hpp>
#include <astrant-extensions/algorithm.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/info_parser.hpp>

using namespace astrant;

TEST_CASE("merge_inplace on empty multimap") {
	std::multimap<std::string, int> map;
	merge_inplace(map, [&](std::string, int&, int&) {
		FAIL("merger called on empty map");
	});
	REQUIRE(map.empty());
}

TEST_CASE("recursive_merge_inplace on empty multimap") {
	std::multimap<std::string, int> map;
	recursive_merge_inplace(map, [&](std::string, int&, int&) {
		FAIL("merger called on empty map");
	});
	REQUIRE(map.empty());
}

TEST_CASE("addition merge_inplace") {
	std::multimap<std::string, int> map;
	map.insert(std::make_pair("foo", 2));
	map.insert(std::make_pair("bar", 3));
	map.insert(std::make_pair("foo", 4));
	bool called = false;
	merge_inplace(map, [&](std::string key, int &a, int &b) {
		REQUIRE(!called);
		called = true;

		CHECK(key == "foo");
		if(a == 2) CHECK(b == 4);
		else if(a == 4) CHECK(b == 2);
		else FAIL("a values are wrong");
		a += b;
	});
	REQUIRE(called);
	REQUIRE(map.size() == 2);
	REQUIRE(map.find("foo") != map.end());
	REQUIRE(map.find("foo")->second == 6);
	REQUIRE(map.find("bar") != map.end());
	REQUIRE(map.find("bar")->second == 3);
}

TEST_CASE("addition recursive_merge_inplace with boost property tree") {
	using boost::property_tree::ptree;
	ptree pt;
	pt.add("foo.num", 2);
	pt.add("bar.num", 3);
	ptree pt_inner;
	pt_inner.add("num", 4);
	pt.add_child("foo", pt_inner);
	CHECK(pt.size() == 3);
	int called = 0;

	recursive_merge_inplace(pt, [&](std::string key, ptree &a, ptree &b) {
		REQUIRE(called < 2);
		if(called == 0) CHECK(key == "foo");
		if(called == 1) CHECK(key == "num");
		called++;

		for(auto &pair : b) {
			a.push_back(pair);
		}

		a.put_value(a.get_value(0) + b.get_value(0));
	});

	REQUIRE(called == 2);
	REQUIRE(pt.size() == 2);
	REQUIRE(pt.get("foo.num", 0) == 6);
	REQUIRE(pt.get("bar.num", 0) == 3);
}

TEST_CASE("string replacement recursive_merge_inplace with multimap") {
	std::multimap<std::string, std::string> map;
	map.insert(std::make_pair("foo", "quux"));
	map.insert(std::make_pair("bar", "mumble"));
	map.insert(std::make_pair("foo", "jambo"));
	bool called = false;
	merge_inplace(map, [&](std::string key, std::string &a, std::string &b) {
		REQUIRE(!called);
		called = true;

		CHECK(key == "foo");
		a = b;
	});
	REQUIRE(called);
	REQUIRE(map.size() == 2);
	REQUIRE(map.find("foo") != map.end());
	REQUIRE(map.find("foo")->second == "jambo");
	REQUIRE(map.find("bar") != map.end());
	REQUIRE(map.find("bar")->second == "mumble");
}

TEST_CASE("string replacement recursive_merge_inplace with boost::property_tree") {
	using boost::property_tree::ptree;
	ptree pt;
	pt.add("foo.str", "quux");
	pt.add("bar.str", "mumble");
	ptree pt_inner;
	pt_inner.add("str", "jambo");
	pt.add_child("foo", pt_inner);
	CHECK(pt.size() == 3);
	int called = 0;

	recursive_merge_inplace(pt, [&](std::string key, ptree &a, ptree &b) {
		REQUIRE(called < 2);
		if(called == 0) CHECK(key == "foo");
		if(called == 1) CHECK(key == "str");
		called++;

		for(auto &pair : b) {
			a.push_back(pair);
		}

		a.put_value(b.get_value(""));
	});
	REQUIRE(called == 2);
	REQUIRE(pt.size() == 2);
	REQUIRE(pt.get("foo.str", "") == "jambo");
	REQUIRE(pt.get("bar.str", "") == "mumble");
}
