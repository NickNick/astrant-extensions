#pragma once

#include <algorithm>

namespace astrant {

/*! Sorted insert using std::lower_bound */
template <typename Container>
typename Container::iterator sorted_insert(Container & c, typename Container::value_type x){
	typename Container::iterator it = std::lower_bound(c.begin(), c.end(), x);
	return c.insert(it, x);
}

/*! Sorted insert using std::lower_bound with comparator */
template <typename Container, typename Comparator>
typename Container::iterator sorted_insert(Container & c, typename Container::value_type x, Comparator comp){
	typename Container::iterator it = std::lower_bound(c.begin(), c.end(), x, comp);
	return c.insert(it, x);
}

}
