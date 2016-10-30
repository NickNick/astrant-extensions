#pragma once

#include <algorithm>
#include <map>
#include <set>

namespace astrant {

/*! Return if \param container contains \param element
	For example: if(contains(x, 5)){}
*/
template <typename C, typename T>
bool contains(C const & container, T const & element){
	return (std::find(container.begin(), container.end(), element) != container.end());
}

template <typename Container, typename Value>
bool contains_with_find_not_end(Container const& c, Value const& v){
	return c.find(v) != c.end();
}

//TODO: Prefer member-function find via SFINAE, remove explicit typing (then also remove the includes)
template <typename Key, typename Value>
bool contains(std::map<Key, Value> const& map, Key const& k){
	return contains_with_find_not_end(map, k);
}

template <typename Value>
bool contains(std::set<Value> const& c, Value const& x){
	return contains_with_find_not_end(c, x);
}

}
