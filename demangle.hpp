#pragma once

#include <cxxabi.h>
#include <stdexcept>

inline std::string demangle(std::string const name){
	int st;
	char * const p = abi::__cxa_demangle(name.c_str(), 0, 0, &st);

	switch (st){
		case -1: throw std::runtime_error("A memory allocation failure occurred.");
		case -2: throw std::runtime_error("Not a valid name under the GCC C++ ABI mangling rules.");
		case -3: throw std::runtime_error("One of the arguments is invalid.");
		default: assert(!"unexpected demangle status"); break;
		case 0: break;
	}

	std::string ret(p);
	free(p);
	return ret;

	// We could return a std::string and free p, but since deallocation is not a concern (and is even a no-op) in geordi anyway, we don't bother.
}


