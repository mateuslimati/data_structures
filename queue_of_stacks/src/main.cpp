/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-10-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <memory>
#include <iostream>
#include <queue.hpp>

int main(int argc, char const *argv[])
{
    try
    {
        auto stk = std::make_unique<dslib::queue::Queue<int>>(10);
        for (int i = 0; i < 10; i++)
        {
            stk->enqueue(i);
        }
        std::cout << "Queue size()=" << stk->size() << std::endl;
        for (int i = 0; i < 10; i++)
        {
            std::cout << "value " << stk->dequeue() << std::endl;
        }
        std::cout << "Queue size()=" << stk->size() << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
