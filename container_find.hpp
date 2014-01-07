#pragma once

#include <boost/optional.hpp>
#include <boost/ref.hpp>

//! Returns a vector of elements which compare true
template <typename Container, typename T>
auto find_multi(Container const& c, T const& element) -> std::vector<boost::cref<Container::value_type>> {
	std::vector<Container::value_type> result;
	for(auto const& e : c){
		if(e == element){
			result.emplace_back(e);
		}
	}

	return result;
}

//! Returns a vector of elements which compare true
template <typename Container, typename T>
auto find_multi(Container& c, T const& element) -> std::vector<boost::ref<Container::value_type>> {
	std::vector<Container::value_type> result;
	for(auto const& e : c){
		if(e == element){
			result.emplace_back(e);
		}
	}

	return result;
}

//! Returns the first element, if it was there.
template <typename Container, typename T>
auto find(Container const& c, T const& element) -> boost::optional<boost::cref<Container::value_type>> {
	for(auto const& e : c){
		if(e == element){
			return e;
		}
	}

	return boost::none;
}

//! Returns the first element, if it was there.
template <typename Container, typename T>
auto find(Container& c, T const& element) -> boost::optional<boost::ref<Container::value_type>> {
	for(auto const& e : c){
		if(e == element){
			return e;
		}
	}

	return boost::none;
}

//! Returns the element, asserts it is there.
template <typename Container, typename T>
auto get(Container const& c, T const& element) -> Container::value_type const& {
	for(auto const& e : c){
		if(e == element){
			return e;
		}
	}
	throw std::runtime_error("Failed to find given element");
}

//! Returns the element, asserts it is there.
template <typename Container, typename T>
auto get(Container& c, T const& element) -> Container::value_type& {
	for(auto&& e : c){
		if(e == element){
			return e;
		}
	}
	throw std::runtime_error("Failed to find given element");
}
