#pragma once

#include <initializer_list>

namespace astrant {

template <typename Container1, typename Container2>
auto append(Container1& x, Container2 const& y) -> decltype(x) {
	using std::begin;
	using std::end;
	x.insert(end(x), begin(y), end(y));
	return x;
}

template <typename Container>
auto append(Container& x, std::initializer_list<typename Container::value_type> const& y) -> decltype(x) {
	x.insert(end(x), begin(y), end(y));
	return x;
}

}

