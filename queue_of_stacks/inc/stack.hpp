/**
 * @file stack.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-10-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <memory>
#include <stdexcept>
#include <mutex>

namespace dslib::stack
{

    template <class T>
    class Stack
    {
    private:
        std::unique_ptr<T[]> arr;
        size_t capacity;
        unsigned long count;

        std::mutex mtx;

    public:
        Stack(const size_t size = 10) : arr(std::make_unique<T[]>(size)),
                                        capacity(size),
                                        count(0){};

        ~Stack(){};

        constexpr bool empty()
        {
            std::scoped_lock lock{this->mtx};
            if (this->count == 0)
            {
                return true;
            }
            return false;
        }

        constexpr size_t size()
        {
            std::scoped_lock lock{this->mtx};
            return this->count;
        }

        void push(T item)
        {
            std::scoped_lock lock{this->mtx};
            if (this->capacity == this->count)
            {
                throw std::overflow_error("Stack overflow!");
            }
            this->arr[this->count++] = item;
        }

        T pop()
        {
            if (this->empty())
            {
                throw std::underflow_error("Stack empty!");
            }
            std::scoped_lock lock{this->mtx};
            return this->arr[--this->count];
        }
    };
}

#endif //__STACK_HPP__