#pragma once

namespace astrant {

// Turns 2 iterators in something having a begin and end, like a range.
//TODO: Allows types of begin/end to differ.
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
