// da3.hpp  
// Grace Kim
// 2024-09-23
//
// For CS 311 Fall 2024
// Header for Assignment 3 functions

#ifndef FILE_DA3_HPP_INCLUDED
#define FILE_DA3_HPP_INCLUDED

#include "llnode.hpp"  // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function

#include <stdexcept>   // For std::out_of_range


//Preconditions: 
//  index >= 0
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head,
                 std::size_t index)
{
    auto p = head;
    if(p == nullptr)
    {
        throw std::out_of_range("index value is out of list's range");
    }

    for(std::size_t i = 0; i < index; i++)
    {
        p = p->_next;

        if(p == nullptr)
        {
            throw std::out_of_range("index value is out of list's range");
        }
    }

    return p->_data;
}


// Implementation in source file
void didItThrow(const std::function<void()> & ff,
                bool & threw);


//Preconditions: 
//  first and last are forward iterators
//  values that iterators point to have < operator
template <typename FDIter>
bool checkSorted(FDIter first,
                 FDIter last)
{
    auto next = first;

    while(next!=last)
    {
        if(*next < *first)
            return false;

        first = next;
        ++next;
    }
    return true; 
}


// Implementation in source file
int gcd(int a,
        int b);


#endif  //#ifndef FILE_DA3_HPP_INCLUDED

