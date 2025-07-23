/**
 * msarray.hpp
 * Grace Kim
 * Sept 12, 2024
 * 
 * Header file for msarray
 * is an array class template 
 */

#ifndef FILE_MSARRAY_HPP_INCLUDED
#define FILE_MSARRAY_HPP_INCLUDED


#include <cstddef>
//for std::size_t

#include <utility>
//for std::swap, std::copy, std::fill

#include <algorithm>
//for std::equal


//Invariants:
//  _size >= 0
template <typename ValType>
class MSArray
{
    public:
        using size_type = std::size_t;
        using value_type = ValType;

    
    //Constructors     
        MSArray() //default ctor
            :_arrayptr{new value_type[8]}, _size{8}
        {
            // intentionally blank
        }

        //Pre: s>=0
        explicit MSArray(size_type s) //ctor: size parameter
            :_arrayptr{new value_type[s]}, _size{s}
        {
            //intentionally blank
        }

        //Pre: s>=0
        MSArray(size_type s, const value_type& v) //ctor: size and type parameters
            :_arrayptr{new value_type[s]}, _size{s}
        {
            std::fill(begin(), end(), v); //set each thing in array from begin() to end() to v 
        }

    //The Big 5
        ~MSArray() //dctor
        {
            delete [] _arrayptr;
        }

        MSArray(const MSArray& other) //copy ctor
            :_arrayptr{new value_type[other._size]}, _size{other._size}
        {
            std::copy(other.begin(), other.end(), _arrayptr); //copies everything in other to this array
        }

        MSArray(MSArray&& other) noexcept //move ctor
            :_arrayptr{other._arrayptr}, _size{other._size}
        {
            other._size = 0;
            other._arrayptr = NULL;
        }

        MSArray& operator=(const MSArray& other) //copy assignment
        {
            auto other_copy = other;
            mswap(other_copy);

            return *this;
        }

        MSArray& operator=(MSArray&& other) noexcept //move assignment
        {
            mswap(other);

            return *this;
        }

    //Member Operators
        
        //Pre: i < _size
        value_type & operator[](size_type i) //bracket operator
        {
            return _arrayptr[i];
        }

        //Pre: i < _size
        const value_type & operator[](size_type i) const //const ver of bracket operator
        {
            return _arrayptr[i];
        }

    //Member Functions
        size_type size() const// returns the size of array
        {
            return _size;
        }

        value_type* begin() // returns address of item [0]
        {
            return _arrayptr;
        }

        const value_type* begin() const //const ver of begin
        {
            return _arrayptr;
        }

        value_type* end()//return address of one past the end
        {
            return _arrayptr+_size;
        }

        const value_type* end() const //const ver of end()
        {
            return _arrayptr+_size;
        }

    private:
        value_type * _arrayptr;
        size_type _size;

        void mswap(MSArray& other) noexcept //member swap function for copy and move assignment 
        {
            std::swap(_arrayptr, other._arrayptr);
            std::swap(_size, other._size);
        }


}; // end of class

//Global Operators

//Pre: arrays are same type
template <typename ValType>
bool operator==(const MSArray <ValType> & a, const MSArray <ValType> & b) //checks if size and values are equal
{
    return std::equal(a.begin(), a.end(), b.begin(), b.end());
}

//Pre: arrays are same type
template <typename ValType> 
bool operator!=(const MSArray<ValType>& a, const MSArray<ValType>& b)//checks if not equal
{
    return !(a==b);
}

//Pre: arrays are same type
template <typename ValType>
bool operator<(const MSArray <ValType> & a, const MSArray <ValType> & b) //checks a<b starting from [0]
{
    for(std::size_t i = 0; i < a.size(); ++i)
    {
        if((a[i] < b[i] || b[i] < a[i]) && i < b.size()) //if a != b and i is valid location in a and b
        {
            return a[i] < b[i];
        }
    }
    return (a.size() < b.size()); //if values are all equal, check size

}

//Pre: arrays are same type
template <typename ValType>
bool operator<=(const MSArray <ValType> & a, const MSArray <ValType> & b) //checks a<=b starting from [0]
{
    return !(b<a);
}

//Pre: arrays are same type
template <typename ValType>
bool operator>(const MSArray <ValType> & a, const MSArray <ValType> & b) //checks a>b starting from [0]
{
    return !(a<=b);
}

//Pre: arrays are same type
template <typename ValType>
bool operator>=(const MSArray <ValType> & a, const MSArray <ValType> & b) //checks a>=b starting from [0]
{
    return !(a<b);
}

#endif //#ifndef FILE_MSARRAY_HPP_INCLUDED