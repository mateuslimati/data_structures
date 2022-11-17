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

import queue;

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
        auto stk = std::make_unique<dslib::queue::Queue<student>>();
        for (int i = 0; i < 10; i++)
        {
            student st(i);
            stk->enqueue(st);
            std::cout << "Student " << st.get_id() << " inserted." << std::endl;
        }
        std::cout << "======================" << std::endl;
        for (int i = 0; i < 4; i++)
        {
            student st = stk->dequeue();
            std::cout << "Student " << st.get_id() << " removed." << std::endl;
        }
        std::cout << "======================" << std::endl;
        for (int i = 2; i > 0; i--)
        {
            student st(i);
            stk->enqueue(st);
            std::cout << "Student " << st.get_id() << " inserted." << std::endl;
        }
        std::cout << "======================" << std::endl;
        for (int i = 0; i < 8; i++)
        {
            student st = stk->dequeue();
            std::cout << "Student " << st.get_id() << " removed." << std::endl;
        }
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
