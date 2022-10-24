 #include <iostream>
#include <gtest/gtest.h>
#include<gtest/gtest.h>

#include<map>


 using namespace std;

 class Student
 {
 public:
     Student(){
         age = 0;
     }
     Student(int a)
     {
         age = a;
     }
     void print()
     {
         cout<<"**********"<<age<<"***********"<<endl;
     }
 private:
     int age;

 };
 class FooEnvironment:public testing::Environment
 {
 public:
     void SetUp() override
     {
         cout<<"Foo Environment SetUp()"<<endl;
     }
     void TearDown() override
     {
         cout<<"Foo Environment TearDown()"<<endl;
     }

 };

 static Student* s;
 static Student* s_1;
//在第一个Test之前，最后一个Test 之后调用SetUpTestCase()和TearDownTestCase()
 class TestMap: public testing::Test
 {
 public:
     static void SetUpTestCase()
     {
         cout<<"SetUpTestCase()"<<endl;
         s = new Student(32);
         s_1 = new Student(23);
     }
     static void TearDownTestCase()
     {
         delete s;
         cout<<"TearDownTestCase()"<<endl;
     }
     void SetUp() override
     {
         cout<<"SetUp() is running"<<endl;
     }
     void TearDown() override
     {
         cout<<"TearDown() is running"<<endl;
     }

 };

 TEST_F(TestMap, Test1)
 {
     s->print();
 }

 TEST_F(TestMap, Test2){
     s_1->print();
 }



 int main(int argc, char *argv[]) {
    printf("Running main() from %s\n", __FILE__);
    testing::AddGlobalTestEnvironment(new FooEnvironment);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
