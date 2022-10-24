//
// Created by c on 2022/10/21.
//

#ifndef GTEST_1_CALCULATOR_FIXTURE_H
#define GTEST_1_CALCULATOR_FIXTURE_H
#include<gtest/gtest.h>
#include"calculator.h"
class CalculatorFixture:public ::testing::TestWithParam<int>
{
public:
    void SetUp() override{};
    void TearDown() override{};
};

INSTANTIATE_TEST_CASE_P(
        CalculatorFixturName,
        CalculatorFixture,
        testing::Values(
                -1,
                0,
                1
                )
        );
class FooEnvironment:public testing::Environment
{
    void SetUp() override;
    void TearDown() override;
};

#endif //GTEST_1_CALCULATOR_FIXTURE_H
