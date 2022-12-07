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

#include <cstddef>
#include <memory>
#include <iostream>
#include <mutex>
#include <queue.hpp>

namespace dslib::stack
{

    template <class T>
    class Stack
    {
    private:
        std::unique_ptr<queue::Queue<T>> queue;
        std::unique_ptr<queue::Queue<T>> temp;
        size_t capacity;
        unsigned long count;

        std::mutex mtx;

    public:
        Stack(const size_t size = 10) : queue(std::make_unique<queue::Queue<T>>(size)),
                                        temp(std::make_unique<queue::Queue<T>>(size)),
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
            size_t queue_size = this->queue->size();
            if (this->capacity == this->count)
            {
                throw std::overflow_error("Stack overflow!");
            }
            try
            {
                this->temp->enqueue(item);
                for (auto i = 0; i < queue_size; i++)
                {
                    this->temp->enqueue(this->queue->dequeue());
                }
                this->temp.swap(this->queue);
                this->count = this->queue->size();
            }
            catch (const std::exception &e)
            {
                throw;
            }
        }

        T pop()
        {
            T item;
            if (this->empty())
            {
                throw std::underflow_error("Stack empty!");
            }
            try
            {
                std::scoped_lock lock{this->mtx};
                item = this->queue->dequeue();
                this->count = this->queue->size();
                return item;
            }
            catch (const std::exception &e)
            {   
                throw;
            }
        }
    };
}

#endif //__STACK_HPP__