#pragma once

#include <cassert>

namespace astrant {

template <typename Container>
auto max(Container const& c) -> typename Container::value_type {
	using Element = typename Container::value_type;
	assert(!c.empty());

	Element max = c[0];

	for(auto const& e : c){
		if (max < e){
			max = e;
		}
	}

	return max;
}

}
