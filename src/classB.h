//#include <thread> 
//#include <chrono>
#include "ClassA.h"
#include "ThreadTimer.cpp"

#pragma once

class ClassB{
private:
    ThreadTimer timer; 
    ClassA& vector_ref;
    int id;
    int freq;
    int range_min;
    int range_max;
    double last_checked_value;
private:
    void Check();
public:
    ClassB(int ID, int N, int L1, int L2, ClassA& obj);
    ~ClassB();
};