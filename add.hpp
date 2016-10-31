#pragma once

#include <set>
#include <initializer_list>

//TODO: Add 'add' function, remove 'append' for not-insertion-order containers (they can have 'add', 'append' doesn't make sense).

namespace astrant {

template <typename Container1, typename Container2>
auto add(Container1& x, Container2 const& y) -> decltype(x) {
	x.insert(end(x), begin(y), end(y));
	return x;
}

template <typename Container2, typename T>
auto add(std::set<T>& x, Container2 const& y) -> decltype(x) {
	x.insert(begin(y), end(y));
	return x;
}

/* add(container, initializer_list) */
template <typename Container>
auto add(Container& x, std::initializer_list<typename Container::value_type> const& y) -> decltype(x) {
	x.insert(end(x), begin(y), end(y));
	return x;
}

template <typename Element>
auto add(std::set<Element>& x, std::initializer_list<Element> const& y) -> decltype(x) {
	x.insert(begin(y), end(y));
	return x;
}

}

