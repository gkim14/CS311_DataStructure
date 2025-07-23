// reverser_test.cpp 
// Grace Kim and Jonathan Brough
// 2024-12-02
//
// For CS 311 Fall 2024
// Test program for class Reverser
// For Assignment 8, Exercise B
// Uses the "doctest" unit-testing framework, version 2
// Requires doctest.h, reverser.hpp

// Includes for code to be tested
#include "reverser.hpp"      // For class Reverser
#include "reverser.hpp"      // Double-inclusion check, for testing only

// Includes for the "doctest" unit-testing framework
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
                             // doctest writes main for us
#include "doctest.h"         // For doctest framework

#include <deque>
using std::deque;
#include <iterator>
using std::begin;
using std::end;
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <array>
using std::array;
#include <string>
using std::string;



// *********************************************************************
// Test Cases
// *********************************************************************

TEST_CASE("Reverser: const and non-const versions")
{
    deque<double> dd { 1.2, 5.2 };
    deque<double> dd_rev { 5.2, 1.2 };
    SUBCASE("const Reverser")
    {
        const Reverser rr;
        rr(begin(dd), end(dd));
        INFO("Reversing with const Reverser");
        REQUIRE(dd == dd_rev);
    }
    SUBCASE("non-const Reverser")
    {
        Reverser rr;
        rr(begin(dd), end(dd));
        INFO("Reversing with non-const Reverser");
        REQUIRE(dd == dd_rev);
    }
}

TEST_CASE("Reverser: data unmodified outside range")
{
    Reverser rr;
    deque<double> dd { 1.2, 5.2, 3.6, 9.8 };
    deque<double> dd_rev { 1.2, 3.6, 5.2, 9.8 };
    rr(begin(dd)+1, end(dd)-1);
    INFO("Reversing middle of a deque of doubles, size 4");
    REQUIRE(dd == dd_rev);
}


/************* Ranges **************/
TEST_CASE("Reverser: different ranges")
{
    Reverser rr;
    SUBCASE("empty range")
    {
        vector<int> vi;
        vector<int> vi_rev;
        rr(begin(vi), end(vi));
        INFO("Reversing vector with empty range");
        REQUIRE(vi == vi_rev);
    }
    SUBCASE("size 1")
    {
        vector<int> vi {1};
        vector<int> vi_rev {1};
        rr(begin(vi), end(vi));
        INFO("Reversing vector of ints, size 1");
        REQUIRE(vi == vi_rev);
    }
    SUBCASE("large range")
    {
        vector<int> vi;
        vector<int> vi_rev;
        for(int i =0; i <= 1000; i++)
        {
            vi.push_back(i);
            vi_rev.push_back(1000-i);
        }
        rr(begin(vi), end(vi));
        INFO("Reversing vector of ints with a large range");
        REQUIRE(vi == vi_rev);
    }
}

/************* Data Structures **************/
TEST_CASE("Reverser: different data structures")
{
    Reverser rr;

    SUBCASE("list")
    {
        list<int> li {2, 3, 4, 5, 6};
        list<int> li_rev {6, 5, 4, 3, 2};
        rr(begin(li), end(li));
        INFO("Reversing list of ints, size 5");
        REQUIRE(li == li_rev);

    }
    SUBCASE("deque")
    {
        deque<double> dd { 1.2, 5.2, 9.6 };
        deque<double> dd_rev { 9.6, 5.2, 1.2 };
        rr(begin(dd), end(dd));
        INFO("Reversing deque of doubles, size 3");
        REQUIRE(dd == dd_rev);
    }
    SUBCASE("vector")
    {
        vector<int> vi {5, 11, 1, 19};
        vector<int> vi_rev{19, 1, 11, 5};
        rr(begin(vi), end(vi));
        INFO("Reversing vector of ints, size 4");
        REQUIRE(vi == vi_rev);
    }
    SUBCASE("array")
    {
        array<string, 2> as {"abc", "def"};
        array<string, 2> as_rev{"def", "abc"};
        rr(begin(as), end(as));
        INFO("Reversing array ofstrings, size 2");
        REQUIRE(as == as_rev);
    }
    SUBCASE("string")
    {
        string s = "abcdef";
        string s_rev = "fedcba";
        rr(begin(s), end(s));
        INFO("Reversing string of size 6");
        REQUIRE(s == s_rev);
    }
}

/************* Value Types **************/
TEST_CASE("Reverser: Different value types")
{
    Reverser rr;
    SUBCASE("int")
    {
        vector<int> vi {5, 11, 1, 19};
        vector<int> vi_rev{19, 1, 11, 5};
        rr(begin(vi), end(vi));
        INFO("Reversing vector of ints, size 4");
        REQUIRE(vi == vi_rev);
    }
    SUBCASE("double")
    {
        vector<double> vd {9.4, 5.4, 2.1, 3.6};
        vector<double> vd_rev{3.6, 2.1, 5.4, 9.4};
        rr(begin(vd), end(vd));
        INFO("Reversing vector of doubles, size 4");
        REQUIRE(vd == vd_rev);
    }
    SUBCASE("string")
    {
        vector<string> vs {"ab", "cd", "ef"};
        vector<string> vs_rev{"ef", "cd", "ab"};
        rr(begin(vs), end(vs));
        INFO("Reversing vector of strings, size 3");
        REQUIRE(vs == vs_rev);
    }
}
