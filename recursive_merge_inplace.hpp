#pragma once

#include <type_traits>

namespace astrant {

template <typename Map, typename Merger>
void recursive_merge_inplace(Map &map, Merger const &merger);

namespace detail {

template <typename...>
struct voider { using type = void; };

template <typename... T>
using void_t = typename voider<T...>::type;

template <typename T, typename U = void>
struct has_key_type : std::false_type {};

template <typename T>
struct has_key_type<T, void_t<typename T::key_type>> : std::true_type {};

template <typename Map, typename Merger, typename std::enable_if<has_key_type<typename Map::mapped_type>::value, int>::type = 0>
void _recursive_merge_inplace(Map &map, Merger const &merger) {
	// Map::mapped_type::key_type exists, so map values are mergeable
	for(auto &it : map) {
		recursive_merge_inplace(it->second, merger);
	}
}

template <typename Map, typename Merger, typename std::enable_if<!has_key_type<typename Map::mapped_type>::value, int>::type = 0>
void _recursive_merge_inplace(Map &, Merger const &) {
	// Map::mapped_type::key_type does not exist, so the merge stops here
}

template <typename Map, typename Merger, typename std::enable_if<!has_key_type<typename Map::data_type>::value, int>::type = 0>
void _recursive_merge_inplace(Map &map, Merger const &merger) {
	// Map::data_type::key_type exists, so map values are mergeable (probably boost::ptree)
	for(auto &it : map) {
		recursive_merge_inplace(it.second, merger);
	}
}

}

/*! Recursively merge a map.
 * See merge_inplace, but recursively called on the children of the map until
 * the children are immergeable or there are no children.
 */
template <typename Map, typename Merger>
void recursive_merge_inplace(Map &map, Merger const &merger) {
	merge_inplace(map, merger);
	detail::_recursive_merge_inplace(map, merger);
}

}
