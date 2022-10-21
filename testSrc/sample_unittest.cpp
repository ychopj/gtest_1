//
// Created by c on 2022/10/19.
//
#include "sample3-inl.h"
#include "gtest/gtest.h"
namespace {
    // To use a test fixture, derive a class from testing::Test.
    class QueueTestSmpl3: public testing::Test{
    protected: //你应该把成员设为受保护的s.t.它们可以从子类访问。
        // 将在运行每个测试之前调用virtual void SetUp（）。如果需要初始化变量。否则，可以跳过。
        void SetUp() override {
            q1_.Enqueue(1);
            q2_.Enqueue(2);
            q2_.Enqueue(3);
        }

        // 每次运行virtual TearDown测试后都将调用virtual TearDown（）。
        //如果有清理工作要做，就应该定义它。否则，你不必提供它。
        virtual void TearDown() {
        }

        //一些测试使用的辅助函数
        static int Double(int n) {
            return 2*n;
        }

        //用于测试Queue:：Map（）的辅助函数
        void MapTester(const Queue<int> *q){
            // 创建一个新队列，其中每个元素的大小是q中相应元素的两倍。
            const Queue<int> *const new_q = q->Map(Double);

            ASSERT_EQ(q->Size(), new_q->Size());
            for (const QueueNode<int>*n1 = q->Head(), *n2 = new_q->Head();
                 n1 != nullptr; n1 = n1->next(), n2 = n2->next()) {
                EXPECT_EQ(2 * n1->element(), n2->element());
            }

            delete new_q;
        }

        //声明测试要使用的变量。
        Queue<int> q0_;
        Queue<int> q1_;
        Queue<int> q2_;
    };



    // When you have a test fixture, you define a test using TEST_F
// instead of TEST.
    TEST_F(QueueTestSmpl3, DefaultConstructor) {
        EXPECT_EQ(0u, q0_.Size());
    }


    TEST_F(QueueTestSmpl3, Dequeue) {
        int * n = q0_.Dequeue();
        EXPECT_TRUE(n == nullptr);

        n = q1_.Dequeue();
        ASSERT_TRUE(n != nullptr);
        EXPECT_EQ(1, *n);
        EXPECT_EQ(0u, q1_.Size());
        delete n;

        n = q2_.Dequeue();
        ASSERT_TRUE(n != nullptr);
        EXPECT_EQ(2, *n);
        EXPECT_EQ(1u, q2_.Size());
        delete n;
    }

    TEST_F(QueueTestSmpl3, EFF) {
        EXPECT_EQ(1u, q1_.Size());
    }

    TEST_F(QueueTestSmpl3, Map) {
        MapTester(&q0_);
        MapTester(&q1_);
        MapTester(&q2_);
    }
}
