//
// Created by c on 2022/10/21.
//
#include"calculator.h"
Calculator::Calculator() {
    Value = 0;
}
Calculator::Calculator(int value) {
    Value = value;
}

void Calculator::calculate(t_operation operation, int operand) {
    switch (operation) {
        case plus:
            Value += operand;
            break;
        case minus:
            Value -= operand;
            break;
        case mul:
            Value *= operand;
        case divi:
            if(operand == 0)
            {
                throw "Division by 0";
            }
            else{
                Value /= operand;
            }
            break;
        default:
            throw"Unsupported operation";
    }
}

int Calculator::value(void) {
    return Value;
}