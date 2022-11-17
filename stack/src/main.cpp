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
#include <stack.hpp>

int main(int argc, char const *argv[])
{
    try
    {
        auto stk = std::make_unique<dslib::stack::Stack<int>>(10);
        for (int i = 0; i < 10; i++)
        {
            stk->push(i);
        }
        std::cout << "Stack size()=" << stk->size() << std::endl;
        for (int i = 0; i < 10; i++)
        {
            std::cout << "value " << stk->pop() << std::endl;
        }
        std::cout << "Stack size()=" << stk->size() << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
