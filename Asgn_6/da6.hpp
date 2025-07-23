/**
 * da6.hpp
 * Grace Kim and Jonathan Brough
 * Nov 5, 2024
 * 
 * Header file for assignment 6
 */

#ifndef FILE_DA6_HPP_INCLUDED
#define FILE_DA6_HPP_INCLUDED

#include "llnode2.hpp"

#include <cstddef>
// For std::size_t
#include <utility>
// For std::pair
// For std::move
#include <memory>
// For std::unique_ptr
#include <stdexcept>
// For std::out_of_range




// Exercise A - Reversing a Linked List
// Pre:
//  head is ptr to null-terminated Linked List, or is null
// Exception Neutral
template<typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>> & head)
{
    std::unique_ptr<LLNode2<ValType>> newHead = nullptr;
    while(head)
    {
        auto p = std::move(head->_next);
        head->_next = std::move(newHead);
        newHead = std::move(head);
        head = std::move(p);
    }
    head = std::move(newHead);
}

// Exercise B - Associative Dataset Class Template
// Invariants:
//   _data_ptr = nullptr or points to an LLNode2
template <typename KeyType,typename ValType >
class SLLMap
{
    public:
        using key_type = KeyType;
        using value_type = ValType;
        using KVTYPE = std::pair<KeyType, ValType>;
    
    // ***** SLLMap: ctors, op=, dctor *****
    public:
        // Default Ctor
        // No Throw Guarantee 
        // Exception Neutral
        SLLMap() 
        : _data_ptr(nullptr)
        {}

        // Dtor
        // No Throw Guarantee
        // Exception Neutral
        ~SLLMap() 
        {
            while(_data_ptr )
            {
                pop_front(_data_ptr);
            }
        }

        // No copy/move operations
        SLLMap(const SLLMap & other) = delete;
        SLLMap & operator=(const SLLMap & other) = delete;
        SLLMap(SLLMap && other) = delete;
        SLLMap & operator=(SLLMap && other) = delete;

    // ***** SLLMap: general public functions *****
    public:
        // size
        // No Throw Guarantee
        // Exception Neutral
        std::size_t size() const noexcept
        {
            auto p = _data_ptr.get();   
            std::size_t counter = 0;  
            while (p != nullptr)
            {
                p = p->_next.get();
                ++counter;
            }
            return counter;
        }

        // empty
        // No Throw Guarantee
        // Exception Neutral
        bool empty() const noexcept
        {
            return size()==0; 
        }

        // present
        // No Throw Guarantee
        // Exception Neutral
        bool present(const key_type& key) const noexcept
        {
            auto p = _data_ptr.get();
            while (p!= nullptr)
            {
                if (p->_data.first == key)
                    return true;
                p = p->_next.get();
            }
            return false;
        }

        // get - const & non-const
        // Strong Guarantee
        // Exception Neutral
        // May throw additional out_of_range exception
        value_type& get(const key_type& key)
        {
            auto p = _data_ptr.get();
            while (p!=nullptr)
            {
                if (p->_data.first == key)
                    return p->_data.second;
                p = p->_next.get();
            }
            throw std::out_of_range("Key not found in SLLMap.");
        }
        const value_type& get(const key_type& key) const
        {
            auto p = _data_ptr.get();
            while (p!=nullptr)
            {
                if (p->_data.first == key)
                    return p->_data.second;
                p = p->_next.get();
            }
            throw std::out_of_range("Key not found in SLLMap.");
        }

        // set
        // Strong Guarantee
        // Exception Neutral
        void set(const key_type& key, const value_type& val)
        {
            auto p = _data_ptr.get();
            while (p!=nullptr)
            {
                if (p->_data.first == key)
                {
                    p->_data.second = val;
                    return;
                }
                p = p->_next.get();
            }
            push_front(_data_ptr, KVTYPE(key, val));
        }

        // erase
        // No Throw Guarantee
        // Exception Neutral
        void erase(const key_type& key) noexcept
        {
            auto p = _data_ptr.get();
            LLNode2<KVTYPE>* prev = nullptr;

            while (p!=nullptr)
            {
                if (p->_data.first == key)
                {
                    if (prev)
                    {
                        prev->_next = std::move(p->_next);
                    }
                    else
                    {
                        _data_ptr = std::move(p->_next);
                    }
                    return;
                }
                prev = p;
                p = p->_next.get();
            }
        }

        // traverse
        // Pre:
        //   ff takes two parameters, key_type and value_type
        // Strong Guarantee
        // Exception Neutral
        template<typename Func>
        void traverse(const Func& ff) const
        {
            auto p = _data_ptr.get();
            while (p!=nullptr)
            {
                ff(p->_data.first, p->_data.second);
                p = p->_next.get();
            }
        }


    // ***** SLLMap: data members *****
    private:
        std::unique_ptr<LLNode2<KVTYPE>> _data_ptr;
};

#endif //#ifndef FILE_DA6_HPP_INCLUDED
