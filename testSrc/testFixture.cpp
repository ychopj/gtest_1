//
// Created by c on 2022/10/18.
//
#include<iostream>
#include<vector>
#include<gtest/gtest.h>

class ListTest: public testing::Test{
protected:
    virtual void SetUp()
    {
        _m_list[0] = 11;
        _m_list[1] = 12;
        _m_list[2] = 13;
    }
    int _m_list[3];
};

TEST_F(ListTest, FirstElement){
    EXPECT_EQ(11, _m_list[0]);
}
TEST_F(ListTest, SecondElement){
    EXPECT_EQ(12, _m_list[1]);
}
TEST_F(ListTest, ThirdElement){
    EXPECT_EQ(13, _m_list[2]);
}