#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <array>

#include <sstream>
#include <iomanip>

namespace std {

template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, std::pair<T, U> const& rh){
	return out << "{" << rh.first << ", " << rh.second << "}";
}

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T> const& rh);

template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, std::map<T, U> const& rh);

template <typename T>
std::ostream& operator<<(std::ostream& out, std::list<T> const& rh);

template <typename T>
std::ostream& operator<<(std::ostream& out, std::set<T> const& rh);

/*! Helper function, outputs a container to the given stream like so {foo bar baz} */
template <typename T>
std::ostream& output_container(std::ostream& out, T const& rh){
	typename T::const_iterator begin = rh.begin();
	typename T::const_iterator end = rh.end();
	
	if(begin == end){
		return out << "{}";
	}
	
	typename T::const_iterator& current = begin;
	out << "{";
	out << *current;
	++current;
	
	while(current != end){
		out << ", " << *current;
		++current;
	}
	
	out << "}";
	
	return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T> const& rh){
	return output_container(out, rh);
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, std::map<T, U> const& rh){
	return output_container(out, rh);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, std::list<T> const& rh){
	return output_container(out, rh);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, std::set<T> const& rh){
	return output_container(out, rh);
}

template <typename T, size_t size>
std::ostream& operator<<(std::ostream& out, std::array<T, size> const& rh){
	return output_container(out, rh);
}

}


