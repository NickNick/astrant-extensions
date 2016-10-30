#pragma once

namespace astrant {

//! Maps @param value to a range of [0, 1]
//! Example to map 0-255 to 0-1: normalize(0, 255, 128)
//! Example to map 1-10 to 0-1: normalize(1, 10, 3)
template <typename T>
T normalize(T const min, T const max, T const value){
	return (value-min)/(max-min);
}

}
