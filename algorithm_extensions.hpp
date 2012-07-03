#pragma once

#include <algorithm>

namespace astrant {

/*! Sorted insert using std::lower_bound */
template <typename Container>
typename Container::iterator sorted_insert(Container c, typename Container::value_type x){
	typename Container::iterator it = std::lower_bound(c.begin(), c.end(), x);
	return c.insert(it, x);
}

/*! Sorted insert using std::lower_bound with comparator */
template <typename Container, typename Comparator>
typename Container::iterator sorted_insert(Container c, typename Container::value_type x, Comparator comp){
	typename Container::iterator it = std::lower_bound(c.begin(), c.end(), x, comp);
	return c.insert(it, x);
}

/*! Return if \param container contains \param element
	@example if(contains(x, 5)){}
*/
template <typename C, typename T>
bool contains(C const & container, T const & element){
	return (std::find(container.begin(), container.end(), element) != container.end());
}

/*! Functor that returns true when passed element is within the container passed at construction
 @example See remove_elements
*/
template <typename U>
struct matches {
	U const& values;
	
	matches(U const& values_) 
	: values(values_)
	{}
	
	template <typename T>
	bool operator()(T x){
		return contains(values, x);
	}
};

/*! Removes \param y from \param x, given x has the member function erase(iterator)
	@example std::vector<int> x = {1, 2, 3, 4, 5}; std::vector<int> y = {2, 4}; remove_elements(x, y);
*/
template<typename T, typename U>
void remove_elements(T& x, U const y){
	x.erase(std::remove_if(x.begin(), x.end(), matches<U>(y)), x.end());
}

/* Remove \param y from \param x, given x has the member function erase(iterator)
	@example std::vector<int> x = {1, 2, 3, 4, 5}; remove_element(x, 3);
*/
template <typename T, typename U>
void remove_element(T& x, U const y){
	x.erase(std::remove(x.begin(), x.end(), y), x.end());
}

}