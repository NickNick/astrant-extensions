#pragma once

#include "rcrr.hpp"
#include "append.hpp"

namespace astrant {

template <typename T>
auto flatten(T const& x) -> rcrr<decltype(*std::begin(x))> {
	rcrr<decltype(*std::begin(x))> y;
	for(auto const& e : x){ append(y, e); }
	return y;
}

}
