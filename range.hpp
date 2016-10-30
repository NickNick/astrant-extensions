#pragma once

#include <cstddef>

namespace astrant {

template <typename T>
struct Range {
        Range(T* _begin, std::size_t const size_)
        : begin_(_begin)
        , end_(_begin + size_)
        {}

        T* begin() const { return begin_; }
        T* end() const { return end_; }
        std::size_t size() const { return end() - begin(); }

        T* begin_;
        T* end_;

        typedef T value_type;
};

template <typename T>
Range<T> make_range(T* begin, std::size_t const size){
        return Range<T>(begin, size);
}

}
