#pragma once

#include <type_traits>

namespace astrant {

template <typename T> using rcrr = typename std::remove_const<typename std::remove_reference<T>::type>::type;

}
