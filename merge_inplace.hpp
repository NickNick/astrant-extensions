#pragma once

#include <map>
#include <algorithm>

namespace astrant {

/*! Merge a map.
 * This function can be used on multi_maps, boost ptrees or other kinds of
 * keyvalue pairs where the key does not have to be unique. The given merger
 * function is called with three parameters: the key (of type Map::key_type),
 * the value to merge into and the value to merge from (both Map::mapped_type).
 * A fully merged map is returned. This only merges the top layer; there is
 * recursive_merge_inplace for a recursive merge.
 */
template <typename Map, typename Merger>
void merge_inplace(Map &map, Merger const &merger) {
	std::map<const typename Map::key_type, int> keys;
	for(auto const &entry : map) {
		keys[entry.first] += 1;
	}

	for(auto &key_it : keys) {
		auto key = key_it.first;
		auto duplicates = key_it.second;
		while(duplicates > 1) {
			auto key_finder = [&](typename Map::value_type const &t) { return t.first == key; };
			auto it1 = std::find_if(map.begin(), map.end(), key_finder);
			auto it2 = std::find_if(std::next(it1), map.end(), key_finder);
			if(it2 == map.end()) {
				// we were expecting another key with this value
				throw std::runtime_error("Map changed while merging it");
			}
			merger(key, it1->second, it2->second);
			map.erase(it2);
			--duplicates;
		}
	}
}

}
