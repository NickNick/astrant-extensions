#pragma once

#include "matches.hpp"

#include <algorithm>
#include <map>
#include <set>

namespace astrant {

/*! Removes \param y from \param x , given x has the member function erase(iterator)
	std::vector<int> x = {1, 2, 3, 4, 5}; std::vector<int> y = {2, 4}; remove_elements(x, y);
*/
template<typename Container, typename Elements>
void remove_elements(Container& x, Elements const y){
	x.erase(std::remove_if(x.begin(), x.end(), matches<Elements>(y)), x.end());
}

/*! Removes \param y from \param x , given x has the member function erase(iterator)
	std::vector<int> x = {1, 2, 3, 4, 5}; remove_element(x, 3);
*/
template <typename Container, typename Element>
void remove_element(Container& x, Element const y){
	x.erase(std::remove(x.begin(), x.end(), y), x.end());
}

template <typename Key, typename Value>
void remove_element(std::map<Key, Value>& x, Key const y){
	x.erase(y);
}

/*! Removes elements from \param x satisfying the predicate \param f
	std::vector<int> x = {1, 2, 3, 4, 5}; remove_elements_if(x, &is_even);
*/
template<typename Container, typename F>
void remove_elements_if(Container& x, F const & f){
	x.erase(std::remove_if(x.begin(), x.end(), f), x.end());
}

}
