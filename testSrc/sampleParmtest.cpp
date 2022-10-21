//
// Created by c on 2022/10/20.
//
#include"sample1.h"
#include<gtest/gtest.h>
namespace{
    //告诉gtest你的参数类型是什么
    //你必须添加一个类，继承testing::TestWithParam<T>,其中T就是你需要参数化的参数类型
class IsPrimeParamTest:public::testing::TestWithParam<int>
{
};
//2.告诉gtest你拿到参数的值后，具体做些什么样的测试
//这里，我们要使用一个新的宏TEST_P(parametetrized)
    TEST_P(IsPrimeParamTest, HandleTrueReturn)
    {
        int n = GetParam();//在TEST_P宏里，使用GetParam()获取当前到参数到具体值
        EXPECT_TRUE(IsPrime(n));
    }
    //3.使用INSTABTIATE_TEST_CASE_P宏来告诉gtest你要测试的参数范围
    //第一个参数是测试案例的前缀，可以任意取
    //第二个参数是测试案例的名称，需要和之前定义到参数化的类的名称相同
    //第三个参数是可以理解微微参数生成器，上面到例子使用test::Values表示使用括号内的参数
    INSTANTIATE_TEST_CASE_P(TrueReturn, IsPrimeParamTest,testing::Values(3,5,7,11, 23, 17));

}