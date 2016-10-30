#pragma once

#include <algorithm>
#include <initializer_list>

namespace astrant {

template <typename Container1, typename Container2>
auto prepend(Container1& x, Container2 const& y) -> decltype(x) {
	x.insert(std::begin(x), std::begin(y), std::end(y));
	return x;
}

template <typename Container>
auto prepend(Container& x, std::initializer_list<typename Container::value_type>&& y) -> decltype(x) {
	x.insert(std::begin(x), std::begin(y), std::end(y));
	return x;
}

}
