// treesort.hpp  
// Grace Kim and Jonathan Brough
// 2024-11-11
//
// For CS 311 Fall 2024
// Header for function template treesort
// There is no associated source file.

#ifndef FILE_TREESORT_HPP_INCLUDED
#define FILE_TREESORT_HPP_INCLUDED

#include <iterator>
// For std::iterator_traits
#include <memory>
// For std::unique_ptr
// For std::make_unique


// Invariants: 
//   _lchild & _rchild are null or point to another BSTNode
template<typename ValType>
struct BSTNode
{
    ValType _data;
    std::unique_ptr<BSTNode<ValType>> _lchild = nullptr;
    std::unique_ptr<BSTNode<ValType>> _rchild = nullptr;

    // No Throw Guarantee
    explicit BSTNode(const ValType& item)
        :_data(item)
    {}
};

// Pre:
//   head is null or points to a BSTNode
//   item has < operator
// Strong Guarantee
// Exception Neutral
template<typename Value>
void insert(std::unique_ptr<BSTNode<Value>> & head, const Value & item)
{
    if(!head)
    {
        head = std::make_unique<BSTNode<Value>> (item); // can throw
        return;
    }
    if(item < head->_data)
        insert(head->_lchild, item);
    else 
        insert(head->_rchild, item); 
}

//Pre:
//   head is null or points to a BSTNode
// No Throw Guarantee
// Exception Neutral
template<typename Value, typename FDIter>
void traverse(const std::unique_ptr<BSTNode<Value>> & head, FDIter& iter)
{
    if(head)
    {
        traverse(head->_lchild, iter);
        *iter++ = head->_data;
        traverse(head->_rchild, iter);
    }
}


// treesort
// Sort a given range using Treesort.
// Pre:
//     [first,last) is valid range
// Strong Guarantee    
// Exception Neutral
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
    // Value is the type that FDIter points to
    using Value = typename std::iterator_traits<FDIter>::value_type;
    
    std::unique_ptr<BSTNode<Value>> head = nullptr;
    for (FDIter it = first; it != last; ++it)
            insert(head, *it); // can throw
    traverse(head, first);
}


#endif //#ifndef FILE_TREESORT_HPP_INCLUDED

