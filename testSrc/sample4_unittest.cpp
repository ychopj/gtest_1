//
// Created by c on 2022/10/18.
//
#include<gtest/gtest.h>
#include"sample4.h"

TEST(Counter, Increment)
{
    Counter c;//define variable in test case

    EXPECT_EQ(1, c.Increment());
    EXPECT_EQ(2, c.Increment());
    EXPECT_EQ(3, c.Increment());

    EXPECT_EQ(2, c.Decrement());
}

