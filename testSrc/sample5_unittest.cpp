//
// Created by c on 2022/10/19.
//
#include<gtest/gtest.h>

#include<limits>
#include <time.h>
#include <climits>
#include"sample1.h"
#include "sample3-inl.h"
namespace
{
class QuickTest: public testing::Test{
protected:
    //the UTC time (in seconds) when the test starts
    time_t start_time_;

    //Remember that SetUp() is run immediately before a test starts
    //this is a good place to record the start time.
    void SetUp() override
    {
        start_time_ = time(nullptr);
    }
    //TearDown() is invoked immediately after a test finished.
    //Here we check if the test was too slow
    void TearDown() override
    {
        const time_t end_time = time(nullptr);//Gets the time when the test finished
        //ASSERT that the test took no more than ~5 seconds
        EXPECT_TRUE(end_time - start_time_ <= 5)<<"The test took too long.";
    }
};
    //We derive a fixture named IntegerFunctionTest from the Quicktest fixture
    //All tests using this fixture will be automatically required to be quick
    class IntegerFunctionTest:public QuickTest
    {

    };

    TEST_F(IntegerFunctionTest, Factorial)
    {
        EXPECT_EQ(1, Factorial(-5));
        EXPECT_EQ(1, Factorial(-1));
        EXPECT_GT(Factorial(-10), 0);

        // Tests factorial of 0.
        EXPECT_EQ(1, Factorial(0));

        // Tests factorial of positive numbers.
        EXPECT_EQ(1, Factorial(1));
        EXPECT_EQ(2, Factorial(2));
        EXPECT_EQ(6, Factorial(3));
        EXPECT_EQ(40320, Factorial(8));
    }
    TEST_F(IntegerFunctionTest, IsPrime)
    {
        // Tests negative input.
        EXPECT_FALSE(IsPrime(-1));
        EXPECT_FALSE(IsPrime(-2));
        EXPECT_FALSE(IsPrime(INT_MIN)); //INT_MIN是边界值

        // Tests some trivial cases.
        EXPECT_FALSE(IsPrime(0));
        EXPECT_FALSE(IsPrime(1));
        EXPECT_TRUE(IsPrime(2));
        EXPECT_TRUE(IsPrime(3));

        // Tests positive input.
        EXPECT_FALSE(IsPrime(4));
        EXPECT_TRUE(IsPrime(5));
        EXPECT_FALSE(IsPrime(6));
        EXPECT_TRUE(IsPrime(23));
    }
    class QueueTest: public QuickTest
    {
    protected:
        void SetUp() override
        {
            //QuickTest::SetUp();
            q1_.Enqueue(1);
            q2_.Enqueue(2);
            q2_.Enqueue(3);

        }

        Queue<int> q0_;
        Queue<int> q1_;
        Queue<int> q2_;
    };
// Now, let's write tests using the QueueTest fixture.

    // Tests the default constructor.
    TEST_F(QueueTest, DefaultConstructor)
    {
        EXPECT_EQ(0, q0_.Size());
    }

    // Tests Dequeue().
    TEST_F(QueueTest, Dequeue)
    {
        int* n = q0_.Dequeue();
        EXPECT_TRUE(n == nullptr);

        n = q1_.Dequeue();
        EXPECT_TRUE(n != nullptr);
        EXPECT_EQ(1, *n);
        EXPECT_EQ(0u, q1_.Size());
        delete n;

        n = q2_.Dequeue();
        EXPECT_TRUE(n != nullptr);
        EXPECT_EQ(2, *n);
        EXPECT_EQ(1u, q2_.Size());
        delete n;
    }

}