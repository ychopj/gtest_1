//
// Created by c on 2022/10/21.
//
#include"calculator.h"
#include<gtest/gtest.h>
#include"../testSuits/calculator_fixture.h"
//Tseting default constructor
TEST(CALCULATORtest, Constructor)
{
    Calculator cal;
    EXPECT_EQ(0, cal.value());
}

//Testimg constructors with one parameter
TEST(CALCULATORtest, ConstructorWithOneParam)
{
    Calculator cal(10);
    EXPECT_EQ(10, cal.value());
}

//Testing calculator plus
TEST(CALCULATORtest, CalculatorPlus)
{
    //Negative
    Calculator cal(-1);
    cal.calculate(t_operation::plus,1);
    EXPECT_EQ(0, cal.value());

    Calculator cal1(-1);
    cal1.calculate(t_operation::plus,-1);
    EXPECT_EQ(-2, cal1.value());

    //positive
    Calculator cal2(1);
    cal2.calculate(t_operation::plus, -2);
    EXPECT_EQ(-1, cal2.value());
}

TEST_P(CalculatorFixture, FixtureUseDemo)
{
    int n = GetParam();
    Calculator cal(-1);
    cal.calculate(t_operation::plus, n);
    EXPECT_EQ((-1)+(n), cal.value());

    Calculator cal2(0);
    cal2.calculate(t_operation::plus, n);
    EXPECT_EQ((0)+(n), cal2.value());

    Calculator cal3(1);
    cal3.calculate(t_operation::plus, n);
    EXPECT_EQ((1)+(n), cal3.value());
}