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
#include <queue.hpp>
#include <gtest/gtest.h>

/**
 * @brief Construct a new TEST object
 *
 */
TEST(QueueOfStacks, SimpleEnqueue)
{
    dslib::queue::Queue<int> queue(2);
    try
    {
        queue.enqueue(1);
        queue.enqueue(2);
        ASSERT_EQ(queue.empty(), false);
        ASSERT_EQ(queue.size(), 2);
        queue.enqueue(3);
    }
    catch (const std::exception &e)
    {
        EXPECT_EQ(e.what(), std::string("Queue overflow!"));
    }
}

/**
 * @brief Construct a new TEST object
 *
 */
TEST(QueueOfStacks, SimpleDequeue)
{
    dslib::queue::Queue<int> queue(1);
    try
    {
        queue.enqueue(2);
        ASSERT_EQ(queue.dequeue(), 2);
        ASSERT_EQ(queue.empty(), true);
        queue.dequeue();
    }
    catch (const std::exception &e)
    {
        EXPECT_EQ(e.what(), std::string("Queue underflow!"));
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