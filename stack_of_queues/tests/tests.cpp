/**
 * @file tests.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-11-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stack.hpp>
#include <gtest/gtest.h>

/**
 * @brief Construct a new TEST object
 *
 */
TEST(Stack, SimplePush)
{
    dslib::stack::Stack<int> stk(2);
    try
    {
        stk.push(1);
        ASSERT_EQ(stk.size(), 1);
        stk.push(2);
        stk.push(3);
    }
    catch (const std::exception &e)
    {
        EXPECT_EQ(e.what(), std::string("Stack overflow!"));
    }
}

/**
 * @brief Construct a new TEST object
 *
 */
TEST(Stack, SimplePop)
{
    dslib::stack::Stack<int> stk(1);
    try
    {
        stk.push(2);
        ASSERT_EQ(stk.pop(), 2);
        ASSERT_EQ(stk.empty(), true);
        stk.pop();
    }
    catch (const std::exception &e)
    {
        EXPECT_EQ(e.what(), std::string("Stack empty!"));
    }
}

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}