#pragma once

#include <initializer_list>

namespace astrant {

template <typename Container>
auto random_element(Container const& c) -> decltype(c[0]){
	return c[random_value(0u, c.size())];
}

template <typename Container>
auto random_element(Container& c) -> decltype(c[0]){
	return c[random_value(0u, c.size())];
}

template <typename Element>
auto random_element(std::initializer_list<Element>&& c) -> decltype(*c.begin()){
	auto const it = c.begin() + random_value(size_t(0), c.size());
	return *it;
}

}
