#include "ClassA.h"
#include "Logger.cpp"
#include "ThreadTimer.cpp"

#pragma once

class ClassB{
private:
    ThreadTimer timer; 
    ClassA& vector_ref;
    Logger& logger_ref;
    int id;
    int freq;
    int range_min;
    int range_max;
    double last_checked_value;
private:
    void Check();
    std::string GetInfo(); 
    std::string GetData();
public:
    ClassB(int ID, int N, int L1, int L2, ClassA& OBJ, Logger& LOG);
    ~ClassB();
};