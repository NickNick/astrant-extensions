#pragma once

namespace astrant {

//! Maps @param value to [@param min , @param max ]
//! Example to map 0-1 to 0-255: normalize(0, 255, 0.5)
//! Example to map 1-10 to 0-1: normalize(1, 10, 0.4)
template <typename T>
T denormalize(T const min, T const max, T const value){
	return (value * (max-min) + min);
}

}
