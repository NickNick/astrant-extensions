#pragma once

#include <limits>
#include <cassert>
#include <string>
#include <stdexcept>

#include "to_string.hpp"

//TODO: namespace astrant {

namespace conversion {
	//! Statically asserts From can be converted to To without loss of information.
	template <typename From, typename To>
	void static_assert_safe_conversion(){
		typedef std::numeric_limits<From> from_traits;
		typedef std::numeric_limits<To> to_traits;
		static_assert(from_traits::lowest() >= to_traits::lowest(), "Minimum value will not fit");
		static_assert(from_traits::max() <= to_traits::max(), "Maximum value will not fit");
		static_assert(from_traits::digits <= to_traits::digits, "Will lose precision upon assignment");
	}

	//! Asserts From can be converted to To without loss of information.
	//! You want this when you have a dynamic type at runtime, and then use a switch/case to call these assertions
	//! Since the wrong instantiation will always be instantiated, we can't use static_assert here.
	//! Needless to say, use static_assert when you can (compile time errors are way more useful)
	template <typename From, typename To>
	void assert_safe_conversion(){
		typedef std::numeric_limits<From> from_traits;
		typedef std::numeric_limits<To> to_traits;
		assert(from_traits::lowest() >= to_traits::lowest());
		assert(from_traits::max() <= to_traits::max());
		assert(from_traits::digits <= to_traits::digits);
	}

	//! Throws if the types are different
	template <typename From, typename To>
	void assert_same_types(){
		try {
			assert_same_types(std::is_same<From, To>());
		} catch ( ... ){
			std::string msg = astrant::to_string(TYPE<From>) + " is not the same as " + astrant::to_string(TYPE<To>);
			assert(!msg.c_str());
			throw std::runtime_error(msg);
		}
	}
}
