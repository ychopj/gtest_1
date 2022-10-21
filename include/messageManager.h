//
// Created by c on 2022/10/18.
//

#ifndef GTEST_1_MESSAGEMANAGER_H
#define GTEST_1_MESSAGEMANAGER_H
#include <string>
using namespace  std;

class messageManager {
public:
    virtual ~messageManager();
    virtual string getMessage() = 0;
};


#endif //GTEST_1_MESSAGEMANAGER_H
