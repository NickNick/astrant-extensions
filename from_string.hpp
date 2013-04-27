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

	template <>
	inline float from_string<float>(std::string const& x){
		return std::stof(x);
	}

	template <>
	inline int from_string<int>(std::string const& x){
		return std::stoi(x);
	}

	template <>
	inline unsigned int from_string<unsigned int>(std::string const& x){
		return std::stoul(x);
	}

	template <>
	inline std::string from_string<std::string>(std::string const& x){
		return x;
	}
}
