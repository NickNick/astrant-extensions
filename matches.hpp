#pragma once

#include "contains.hpp"

namespace astrant {

/*! Functor that returns true when passed element is within the container passed at construction
	See remove_elements
*/
template <typename U>
struct matches {
	U const& values;

	matches(U const& values_)
	: values(values_)
	{}

	template <typename T>
	bool operator()(T const& x){
		return contains(values, x);
	}
};

}
