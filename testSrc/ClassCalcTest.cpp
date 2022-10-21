//
// Created by c on 2022/10/19.
//
#include<gtest/gtest.h>
#include"Calc.h"

Calc calculation;

TEST(CalcClassTest, add)
{
    EXPECT_EQ(3, calculation.Add(1, 2));
}

TEST(CalcClassTest, minus)
{
    EXPECT_EQ(calculation.Minus(1,2), -1);
}

TEST(CalcClassTest, multi)
{
    EXPECT_EQ(calculation.Multi(1,2), 2);
}

TEST(CalcClassTest, devide)
{
    EXPECT_FLOAT_EQ(calculation.Divide(1,2), 0.5);
}

TEST(StringTest, BasicTest)
{
    strcpy(calculation.name, "Google Test");

    EXPECT_STREQ("Google Test", calculation.name);
    EXPECT_STRNE("CppUnit Test", calculation.name);

    strcpy(calculation.name, "CppUnit Test");
    EXPECT_STRNE(calculation.name, "CppUnit Test");

    ASSERT_STRCASEEQ("cppunit test", calculation.name);
    ASSERT_STRCASENE("gppunit test", calculation.name);
}