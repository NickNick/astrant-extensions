#pragma once

#include <sstream>
#include <string>
#include <stdexcept>
 
namespace astrant {
	using std::string;
	using std::stringstream;

	template <typename T>
	T from_string(std::string const& x){
		stringstream s;
		s << x;
		T y;
		s >> y;
		if(!s){
			throw std::runtime_error("Failed to convert \"" + x + "\" to requested type");
		}
		return y;
	}
}