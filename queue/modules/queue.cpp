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

module;

#include <memory>
#include <stdexcept>
#include <mutex>

export module queue;

export namespace dslib::queue
{

    template <class T>
    class Queue
    {
    private:
        std::unique_ptr<T[]> arr;
        size_t capacity;
        unsigned long count;
        unsigned long front;
        unsigned long rear;

        std::mutex mtx;

    public:
        Queue(const size_t size = 10) : arr(std::make_unique<T[]>(size)),
                                        capacity(size),
                                        count(0),
                                        front(0),
                                        rear(0){};

        ~Queue(){};

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

        void enqueue(T item)
        {
            std::scoped_lock lock{this->mtx};
            if (this->capacity == this->count)
            {
                throw std::overflow_error("Queue overflow!");
            }
            if (this->rear == this->capacity)
            {
                this->rear = 0;
            }
            this->arr[this->rear++] = item;
            this->count++;
        }

        T dequeue()
        {
            std::scoped_lock lock{this->mtx};
            if (this->count == 0)
            {
                throw std::overflow_error("Queue underflow!");
            }
            T item = this->arr[this->front];
            this->front = ((this->front + 1) % this->capacity);
            this->count--;
            return item;
        }
    };
}
