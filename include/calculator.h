//
// Created by c on 2022/10/21.
//

#ifndef GTEST_1_CALCULATOR_H
#define GTEST_1_CALCULATOR_H

typedef enum op
{
    plus,
    minus,
    mul,
    divi
}t_operation;

class Calculator
{
public:
    Calculator();
    Calculator(int value);
    void calculate(t_operation operation, int operand);
    int value(void);
private:
    int Value;
};

#endif //GTEST_1_CALCULATOR_H
