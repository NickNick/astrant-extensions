#pragma once

#include <sstream>
#include <string>

namespace astrant {
	using std::string;
	using std::stringstream;

	template <typename T>
	string to_string(T const& x){
		stringstream s;
		s << x;
		return s.str();
	}
}

/* The standard mingw distribution reports a broken VSWPRINTF and thus has no 
 * std::to_string. In these cases we use a replacement to_string and put it in 
 * the std namespace. The mingw64 on the other hand has a working implementation
 * this is why we check for the existance of win32 and this flag.
 */
#if defined ( _WIN32 ) && _GLIBCXX_HAVE_BROKEN_VSWPRINTF == 1
namespace std {
	using astrant::to_string;
}
#endif