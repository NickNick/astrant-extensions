#pragma once

#include <iostream>
#include <iomanip>
#include <string>

namespace astrant {
	inline std::string cut_left_if_too_large(std::string s, size_t size){
		if(s.size() > size){
			return s.substr(s.size() - size);
		} else {
			return s;
		}
	}
}

#define ASTRANT_STRING_CURRENT_PLACE_INFORMATION (astrant::cut_left_if_too_large(__FILE__, 20) + ":" + std::to_string(__LINE__) + "(" + __FUNCTION__ + ")")
#define ASTRANT_STREAM_CURRENT_PLACE_INFORMATION (astrant::cut_left_if_too_large(__FILE__, 20) + ":") << std::setw(4) << std::to_string(__LINE__) << "(" <<  std::setw(15) << __FUNCTION__ << ")"

#define ACOUT  std::cout << ASTRANT_STREAM_CURRENT_PLACE_INFORMATION  << "\n"
#define ASDOUT std::cout << ASTRANT_STREAM_CURRENT_PLACE_INFORMATION  << ": "
#define ACERR  std::cerr << ASTRANT_STREAM_CURRENT_PLACE_INFORMATION  << "\n"
#define ASDERR std::cerr << ASTRANT_STREAM_CURRENT_PLACE_INFORMATION  << ": "
