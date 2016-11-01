#pragma once

#include "random_value.hpp"
#include <initializer_list>

namespace astrant {

template <typename Container>
auto random_element(Container const& c) -> decltype(c[0]){
	auto e = c.size();
	auto b = e;
	b = 0;
	return c[random_value(b, e)];
}

template <typename Container>
auto random_element(Container& c) -> decltype(c[0]){
	auto e = c.size();
	auto b = e;
	b = 0;
	return c[random_value(b, e)];
}

template <typename Element>
auto random_element(std::initializer_list<Element>&& c) -> decltype(*c.begin()){
	auto e = c.size();
	auto b = e;
	b = 0;
	auto const it = c.begin() + random_value(b, e);
	return *it;
}

}
