#pragma once

#include <sstream>
#include <string>
 
namespace astrant {
	using std::string;
	using std::stringstream;

	template <typename T>
	T from_string(std::string const& x){
		stringstream s;
		s << x;
		T y;
		s >> y;
		return y;
	}
}