#pragma once

#include <algorithm>
#include <set>
#include <initializer_list>

//TODO: Add 'add' function, remove 'append' for not-insertion-order containers (they can have 'add', 'append' doesn't make sense).

namespace astrant {

template <typename Container1, typename Container2>
auto append(Container1& x, Container2 const& y) -> decltype(x) {
	x.insert(std::end(x), std::begin(y), std::end(y));
	return x;
}

template <typename Container2, typename T>
auto append(std::set<T>& x, Container2 const& y) -> decltype(x) {
	x.insert(std::begin(y), std::end(y));
	return x;
}

template <typename Container>
auto append(Container& x, std::initializer_list<typename Container::value_type>&& y) -> decltype(x) {
	x.insert(std::end(x), std::begin(y), std::end(y));
	return x;
}

template <typename Element>
auto append(std::set<Element>& x, std::initializer_list<Element>&& y) -> decltype(x) {
	x.insert(std::begin(y), std::end(y));
	return x;
}

}

