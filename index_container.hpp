#pragma once

#include <vector>
#include <deque>

template <typename T>
struct index_container
{
    typedef std::vector<T>                 inner_list;
    typedef typename inner_list::size_type size_type;
    typedef std::deque<size_type>          index_list;

    index_container() {}

    index_container(size_type count, const T &value)
    : data_(count, value)
    , indices_(count, 0)
    {
        for(size_type i = 0; i < count; ++i) {
            indices_[i] = i;
        }
    }

    size_type push_back(const T &x) {
        data_.push_back(x);
        unsigned int index = data_.size() - 1;
        indices_.push_back(index);
        return index;
    }

    size_type push_front(const T &x) {
        data_.push_back(x);
        unsigned int index = data_.size() - 1;
        indices_.push_front(index);
        return index;
    }

    template<class... Args>
    size_type emplace_back( Args&&... x) {
        data_.emplace_back(x...);
        unsigned int index = data_.size() - 1;
        indices_.push_back(index);
        return index;
    }

    template<class... Args>
    size_type emplace_front( Args&&... x) {
        data_.emplace_back(x...);
        unsigned int index = data_.size() - 1;
        indices_.push_front(index);
        return index;
    }

    const T &at(size_type t) const {
        return data_.at(t);
    }

    T &at(size_type t) {
        return data_.at(t);
    }

    const T &operator[](size_type t) const {
        return data_[t];
    }

    T &operator[](size_type t) {
        return data_[t];
    }

    const T &front() const {
        return data_.at(indices_.front());
    }

    T &front() {
        return data_.at(indices_.front());
    }

    const T &back() const {
        return data_.at(indices_.back());
    }

    T &back() {
        return data_.at(indices_.back());
    }

    const index_list &indices() const {
        return indices_;
    }

    const inner_list &data() const {
        return data_;
    }

    void reserve(size_type t) const {
        data_.reserve(t);
        indices_.reserve(t);
    }

    bool empty() const {
        return indices_.empty();
    }

    size_type size() const {
        return indices_.size();
    }

    void clear() {
        indices_.clear();
        data_.clear();
    }

private:
    inner_list data_;
    index_list indices_;
};
