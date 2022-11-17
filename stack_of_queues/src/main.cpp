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

import stack;

class student
{
private:
    int id;

public:
    student(const int id = 0);
    ~student();

    constexpr int get_id();
};

student::student(const int id) : id(id)
{
}

student::~student()
{
}

constexpr int student::get_id()
{
    return this->id;
}

int main(int argc, char const *argv[])
{
    try
    {
        // std::cout << sizeof(student) << std::endl;
        // auto stk = std::make_unique<stack::Stack<student>>(10);
        // std::cout << sizeof(stk) << std::endl;

        // for (int i = 0; i < 10; i++)
        // {
        //     auto st = std::make_unique<student>(i);
        //     stk->push(*st);
        // }
        // std::cout << "Stack size()=" << stk->size() << std::endl;
        // for (int i = 0; i < 10; i++)
        // {
        //     auto st = stk->pop();
        //     std::cout << "Student " << st.get_id() << std::endl;
        // }
        // std::cout << "Stack size()=" << stk->size() << std::endl;
        // return 0;
        int *ptr = new int[20];
        delete ptr;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
