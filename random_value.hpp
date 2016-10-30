#pragma once

#include <cstdlib>
#include "denormalize.hpp"

namespace astrant {

//! Gives a random value [@param min , @param max ]
template <typename T>
T random_value(T const& min, T const& max){
	float between_zero_and_one_inclusive = (std::rand()/float(RAND_MAX));
	T returnValue = denormalize(float(min), float(max), between_zero_and_one_inclusive);
	return returnValue;
}

}
