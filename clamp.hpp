#pragma once

namespace astrant {

template <typename T>
void clamp(T min, T& v, T max) {
	if (v < min) v = min;
	if (v > max) v = max;
}

template <typename T>
auto clamped(T min, T val, T max){
	clamp(min, val, max);
	return val;
}

}
