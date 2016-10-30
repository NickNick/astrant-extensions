#pragma once

#include <array>

namespace astrant {

template <typename T, size_t size>
T product(std::array<T, size> const& x){
	static_assert(size > 0, "Size must be > 0 to get the product from this array");
	//TODO: Enable when supported by the compiler (gcc 4.6.3 on ubuntu 12.04 doesn't support this yet)
	//static_assert(std::is_copy_constructible<T>, "T must be copy-constructible");

	T return_value = x[0];
	for(size_t i = 1; i < size; ++i){
		return_value *= x[i];
	}

	return return_value;
}

}
