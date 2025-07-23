/**
 * gfsarray.hpp
 * Grace Kim and Jonathan Brough
 * Oct 28, 2024
 * 
 * Header file for gfsarray
 * template class for frightfully smart array
 */




#ifndef FILE_GFSARRAY_HPP_INCLUDED
#define FILE_GFSARRAY_HPP_INCLUDED

#include <cstddef>
//for std::size_t
#include <utility>
//for std::copy
#include <algorithm>
// For std::max

// *********************************************************************
// class GFSArray - Class definition
// *********************************************************************


// class GFSArray
// Frightfully Smart Array template
// Resizable, copyable/movable, exception-safe.
// Invariants:
//     0 <= _size <= _capacity.
//     _data points to an array of value_type, allocated with new [],
//      owned by *this, holding _capacity value_type values -- UNLESS
//      _capacity == 0, in which case _data may be nullptr.
template <typename ValType>
class GFSArray
{
    public:
        using size_type = std::size_t;
        using value_type = ValType;
        using iterator = value_type *;
        using const_iterator = const value_type;

    // ***** GFSArray: internal-use constants *****
    private:

    // Capacity of default-constructed object
    enum { DEFAULT_CAP = 42 };

    // ***** GFSArray: ctors, op=, dctor *****
    public:
        // Default ctor & ctor from size
        // Strong Guarantee
        explicit GFSArray(size_type thesize=0)
            :_capacity(std::max(thesize, size_type(DEFAULT_CAP))),
                // _capacity must be declared before _data
            _size(thesize),
            _data(_capacity == 0 ? nullptr
                                : new value_type[_capacity])
        {}

         // Copy ctor
        // Strong Guarantee
        GFSArray(const GFSArray & other)
        
            :_capacity(other._capacity),
            _size(other.size()),
            _data(other._capacity == 0 ? nullptr
                                        : new value_type[other._capacity])
        {
            std::copy(other.begin(), other.end(), begin());
            // The above call to std::copy does not throw, since it copies int
            // values. But if value_type is changed, then the call may throw, in
            // which case this copy ctor may need to be rewritten.
        }

        // Move ctor
        // No-Throw Guarantee
        GFSArray::FSArray(GFSArray && other) noexcept
            :_capacity(other._capacity),
            _size(other._size),
            _data(other._data)
        {
            other._capacity = 0;
            other._size = 0;
            other._data = nullptr;
        }

        // Copy assignment operator
        // ??? Guarantee
        GFSArray & GFSArray::operator=(const GFSArray & other)
        {
            // TODO: WRITE THIS!!!
            return *this; // DUMMY
        }

        // Move assignment operator
        // No-Throw Guarantee
        GSArray & GSArray::operator=(GSArray && other) noexcept
        {
            // TODO: WRITE THIS!!!
            return *this; // DUMMY
        }

        // Dctor
        // No-Throw Guarantee
        ~GSArray()
        {
            delete [] _data;
        }

    // ***** GFSArray: general public operators *****
    public:

        // operator[] - non-const & const
        // Pre:
        //     ???
        // No-Throw Guarantee
        value_type & operator[](size_type index)
        {
            return _data[index];
        }
        const value_type & operator[](size_type index) const
        {
            return _data[index];
        }
    // ***** GFSArray: general public functions *****
    public:

        // size
        // No-Throw Guarantee
        size_type size() const noexcept
        {
            return _size;
        }

        // empty
        // No-Throw Guarantee
        bool empty() const noexcept
        {
            return size() == 0;
        }

        // resize
        // ??? Guarantee
        void resize(size_type newsize)
        {
            // TODO: WRITE THIS!!!
        }

        // insert
        // Pre:
        //     ???
        // ??? Guarantee
        iterator insert(iterator pos,
                        value_type item)
        {
            // TODO: WRITE THIS!!!
            return begin();  // DUMMY
        }
            // Above, passing by value is appropriate, since our value type
            // is int. However, if the value type is changed, then a
            // different parameter-passing method may need to be used.

        // erase
        // Pre:
        //     ???
        // ??? Guarantee
        iterator erase(iterator pos)
        {
            // TODO: WRITE THIS!!!
            return begin();  // DUMMY
        }

        // begin - non-const & const
        // No-Throw Guarantee
        iterator begin() noexcept
        {
            return _data;
        }
        const_iterator begin() const noexcept
        {
            return _data;
        }

        // end - non-const & const
        // No-Throw Guarantee
        iterator end() noexcept
        {
            return begin() + size();
        }
        const_iterator end() const noexcept
        {
            return begin() + size();
        }

        // push_back
        // ??? Guarantee
        void push_back(value_type item)
            // Above, passing by value is appropriate, since our value type
            // is int. However, if the value type is changed, then a
            // different parameter-passing method may need to be used.
        {
            insert(end(), item);
        }

        // pop_back
        // Pre:
        //     ???
        // ??? Guarantee
        void pop_back()
        {
            erase(end()-1);
        }

        // swap
        // No-Throw Guarantee
        void swap(GFSArray & other) noexcept
        {
            // TODO: WRITE THIS!!!
        }


    // ***** GFSArray: data members *****
    private:

        // Below, _capacity must be declared before _data
        size_type    _capacity;  // Size of our allocated array
        size_type    _size;      // Size of client's data
        value_type * _data;      // Pointer to our array

};

#endif      //ifndef FILE_GFSARRAY_HPP_INCLUDED