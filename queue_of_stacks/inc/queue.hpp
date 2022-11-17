/**
 * @file queue.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-10-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include <memory>
#include <stdexcept>
#include <mutex>
#include <iostream>
#include <stack.hpp>

namespace dslib::queue
{

    template <class T>
    class Queue
    {
    private:
        std::unique_ptr<dslib::stack::Stack<T>> stack;
        std::unique_ptr<dslib::stack::Stack<T>> temp;
        size_t capacity;
        unsigned long count;
        unsigned long front;
        unsigned long rear;

        std::mutex mtx;

    public:
        Queue(const size_t size = 10) : stack(std::make_unique<dslib::stack::Stack<T>>(size)),
                                        temp(std::make_unique<dslib::stack::Stack<T>>(size)),
                                        capacity(size),
                                        count(0){};

        ~Queue(){};

        constexpr bool empty()
        {
            std::scoped_lock lock{this->mtx};
            return this->stack->empty();
        }

        constexpr size_t size()
        {
            std::scoped_lock lock{this->mtx};
            return this->stack->size();
        }

        void enqueue(T item)
        {
            std::scoped_lock lock{this->mtx};
            if (this->capacity == this->count)
            {
                throw std::overflow_error("Queue overflow!");
            }
            try
            {
                auto stack_size = this->stack->size();
                for (auto i = 0; i < stack_size; i++)
                {
                    T temp = this->stack->pop();
                    this->temp->push(temp);
                }
                this->temp->push(item);
                stack_size = this->temp->size();
                for (auto i = 0; i < stack_size; i++)
                {
                    T temp = this->temp->pop();
                    this->stack->push(temp);
                }
                this->count = this->stack->size();
            }
            catch (const std::exception &e)
            {
                throw;
            }
        }

        T dequeue()
        {
            std::scoped_lock lock{this->mtx};
            if (this->count == 0)
            {
                throw std::overflow_error("Queue underflow!");
            }
            try
            {
                T item = this->stack->pop();
                this->count = this->stack->size();
                return item;
            }
            catch (const std::exception &e)
            {
                throw;
            }
        }
    };
}

#endif //__QUEUE_HPP__