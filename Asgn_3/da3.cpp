// da3.cpp  
// Grace Kim
// 2024-09-23
//
// For CS 311 Fall 2024
// Source for Assignment 3 functions

#include "da3.hpp"     // For Assignment 3 prototypes & templates

#include <functional>
using std::function;


//Preconditions: 
//  ff takes no parameters
//  ff returns nothing
//May throw whatever function ff throws
void didItThrow(const function<void()> & ff,
                bool & threw)
{
    try
    {
        ff();
        threw = false;
    }
    //catch all
    catch(...)
    {
        threw = true; 

        //throws whatever was caught
        throw;
    }
}

//Preconditions: 
//  (a && b) != 0
//  a && b are nonnegative
//Does not throw
int gcd(int a,
        int b)
{
    //base case/ rule 1
    if(a == 0)
        return b; 

    //rule 2
    else if(a > b)
        return gcd(b, a);
    //rule 3
    else 
        return gcd(b%a, a);
}

