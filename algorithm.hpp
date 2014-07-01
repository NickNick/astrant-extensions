#pragma once

#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <type_traits>
#include <array>

namespace astrant {
//! Maps @param value to a range of [0, 1]
//! Example to map 0-255 to 0-1: normalize(0, 255, 128)
//! Example to map 1-10 to 0-1: normalize(1, 10, 3)
template <typename T>
T normalize(T const min, T const max, T const value){
	return (value-min)/(max-min);
}

//! Maps @param value to [@param min , @param max ]
//! Example to map 0-1 to 0-255: normalize(0, 255, 0.5)
//! Example to map 1-10 to 0-1: normalize(1, 10, 0.4)
template <typename T>
T denormalize(T const min, T const max, T const value){
	return (value * (max-min) + min);
}

//! Gives a random value [@param min , @param max ]
template <typename T>
T random_value(T const& min, T const& max){
	float between_zero_and_one_inclusive = (rand()/float(RAND_MAX));
	T returnValue = denormalize(float(min), float(max), between_zero_and_one_inclusive);
	return returnValue;
}

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

/*! Return if \param container contains \param element
	@example if(contains(x, 5)){}
*/
template <typename C, typename T>
bool contains(C const & container, T const & element){
	return (std::find(container.begin(), container.end(), element) != container.end());
}

template <typename Key, typename Value>
bool contains(std::map<Key, Value> const& map, Key const& k){
	return map.find(k) != map.end();
}

template <typename Value>
bool contains(std::set<Value> const& c, Value const& x){
	return c.find(x) != c.end();
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
	bool operator()(T const& x){
		return contains(values, x);
	}
};

/*! Removes \param y from \param x , given x has the member function erase(iterator)
	@example std::vector<int> x = {1, 2, 3, 4, 5}; std::vector<int> y = {2, 4}; remove_elements(x, y);
*/
template<typename Container, typename Elements>
void remove_elements(Container& x, Elements const y){
	x.erase(std::remove_if(x.begin(), x.end(), matches<Elements>(y)), x.end());
}

/*! Removes \param y from \param x, given x has the member function erase(iterator)
	@example std::vector<int> x = {1, 2, 3, 4, 5}; remove_element(x, 3);
*/
template <typename Container, typename Element>
void remove_element(Container& x, Element const y){
	x.erase(std::remove(x.begin(), x.end(), y), x.end());
}

/*! Removes elements from \param x satisfying the predicate \param f
	@example std::vector<int> x = {1, 2, 3, 4, 5}; remove_elements_if(x, &is_even);
*/
template<typename Container, typename F>
void remove_elements_if(Container& x, F const & f){
	x.erase(std::remove_if(x.begin(), x.end(), f), x.end());
}

template <typename Container>
auto random_element(Container const& c) -> decltype(c[0]){
	return c[random_value(size_t(0), c.size())];
}

template <typename Container>
auto random_element(Container& c) -> decltype(c[0]){
	return c[random_value(size_t(0), c.size())];
}

template <typename Element>
auto random_element(std::initializer_list<Element>&& c) -> decltype(*c.begin()){
	auto const it = c.begin() + random_value(size_t(0), c.size());
	return *it;
}

template <typename Container1, typename Container2>
auto append(Container1& x, Container2 const& y) -> decltype(x) {
	x.insert(std::end(x), std::begin(y), std::end(y));
	return x;
}

template <typename Container2, typename T>
auto append(std::set<T>& x, Container2 const& y) -> decltype(x) {
	x.insert(std::begin(y), std::end(y));
	return x;
}

template <typename Container>
auto append(Container& x, std::initializer_list<typename Container::value_type>&& y) -> decltype(x) {
	x.insert(x.end(), y.begin(), y.end());
	return x;
}

template <typename Element>
auto append(std::set<Element>& x, std::initializer_list<Element>&& y) -> decltype(x) {
	x.insert(y.begin(), y.end());
	return x;
}

template <typename T> using rcrr = typename std::remove_const<typename std::remove_reference<T>::type>::type;

template <typename T>
auto flatten(T const& x) -> rcrr<decltype(*std::begin(x))> {
	rcrr<decltype(*std::begin(x))> y;
	for(auto const& e : x){ append(y, e); }
	return y;
}

template <typename Container>
auto max(Container const& c) -> typename Container::value_type {
	using Element = typename Container::value_type;
	assert(!c.empty());

	Element max = c[0];

	for(auto const& e : c){
		if (max < e){
			max = e;
		}
	}

	return max;
}

template <typename T, size_t size>
T product(std::array<T, size> const& x){
	static_assert(size > 0, "Size must be > 0 to get the product from this array");
	//TODO: Enable when supported by the compiler (gcc 4.6.3 on ubuntu 12.04 doesn't support this yet)
	//static_assert(std::is_copy_constructible<T>, "T must be copy-constructible");

	T return_value = x[0];
	for(size_t i = 1; i < size; ++i){
		return_value *= x[i];
	}

	return return_value;
}

template <typename T>
struct Range {
        Range(T* _begin, size_t const size)
        : begin_(_begin)
        , end_(_begin + size)
        {}

        T* begin() const { return begin_; }
        T* end() const { return end_; }
        size_t size() const { return end() - begin(); }

        T* begin_;
        T* end_;

        typedef T value_type;
};

template <typename T>
Range<T> make_range(T* begin, size_t const size){
        return Range<T>(begin, size);
}

template <typename Iterator>
struct IteratorPair {
        IteratorPair(Iterator begin_, Iterator end_)
        : _begin(begin_)
        , _end(end_)
        {}

        Iterator begin() const {
                return _begin;
        }

        Iterator end() const {
                return _end;
        }   
            
        Iterator _begin;
        Iterator _end;
};

}
