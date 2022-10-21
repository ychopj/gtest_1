//
// Created by c on 2022/10/21.
//
#include<gtest/gtest.h>
#include<stack>
#include<string>
using namespace std;

TEST(testStack,simpletest){
    stack<int> st;
    st.push(4);

    EXPECT_EQ(4, st.top());
}

TEST(testStack, testAll)
{
    stack<int> st;
    st.push(9);
    st.push(28);

    int val = st.top();
    st.pop();
    EXPECT_EQ(28, val);
    EXPECT_NE(0, val);
    EXPECT_GT(29, val);
    EXPECT_GE(29, val);
    EXPECT_TRUE(val == 28) <<"val is not equal to 28";
}
TEST(testStack, testAll1)
{
    stack<int> st;
    st.push(9);
    st.push(28);

    int val = st.top();
    st.pop();
    ASSERT_EQ(28, val);
    ASSERT_NE(0, val);
    ASSERT_GT(29, val);
    ASSERT_TRUE(val == 28) <<"val is not equal to 28";
}

TEST(testStack, testAll_string)
{
    stack<int> st;
    st.push(9);
    st.push(28);

    int val = st.top();
    st.pop();
    EXPECT_EQ("9", to_string(val).c_str());
    EXPECT_FLOAT_EQ(7.0, ((float)val)/4);
}