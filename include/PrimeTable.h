//
// Created by c on 2022/10/19.
//
#pragma once
//This provides interface PrimeTable that determines whether a number is a primer and
//determines a next prime number
#ifndef GTEST_1_PRIMETABLE_H
#define GTEST_1_PRIMETABLE_H

#include<iostream>
using namespace std;
//The prime table interface定义接口，未具体实现
class PrimeTable
{
public:
    virtual ~PrimeTable(){}
    virtual bool IsPrime(int n) const =0 ;
    virtual int GetNextPrime(int p) const = 0;
};
//接口实现一：直接计算素数
class OnTheFlyPrimeTable:public PrimeTable
{
public:
    bool IsPrime(int n) const override
    {
        if(n<=1) return false;
        for(int i = 2; i * i <= n; i++)
            if((n % i) == 0) return false;
        return true;
    }
    int GetNextPrime(int p) const override
    {
        if(p < 0) return -1;

        for(int n = p+1;;n++)
        {
            if(IsPrime(n)) return n;
        }
    }
};
//接口实现二：引入数组，对素数进行标记
class PreCalculatedPrimeTable:public PrimeTable{
private:
    const int is_prime_size_;//is_prime_size_定义了素数表中的最大数
    bool* const is_prime_;
public:
    explicit PreCalculatedPrimeTable(int max):is_prime_size_(max+1), is_prime_(new bool[max + 1])
    {
        CalculatePrimesUpTo(max);//
    }
    ~PreCalculatedPrimeTable() override {delete[] is_prime_;}

    bool IsPrime(int n) const override
    {
        return 0<=n && n < is_prime_size_ && is_prime_[n];
    }
    int GetNextPrime(int p) const override
    {
        for(int n = p + 1; n < is_prime_size_; n++)
        {
            if(is_prime_[n]) return n;
        }
        return -1;
    }

private:
    void CalculatePrimesUpTo(int max)
    {
        fill(is_prime_, is_prime_ + is_prime_size_, true);
        is_prime_[0] = is_prime_[1] = false;
        for(int i = 2; i * i <= max; i += i % 2 + 1)
        {
            if(!is_prime_[i]) continue;

            for(int j = i*i; j <= max; j += i)
            {
                is_prime_[j] = false;
            }
        }
    }

    void operator=(const PreCalculatedPrimeTable &rhs);

};



#endif //GTEST_1_PRIMETABLE_H
