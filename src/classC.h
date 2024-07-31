#include "ClassA.h"
#include "Logger.cpp"
#include "ThreadTimer.cpp"

#pragma once

class ClassC{
private:
    ThreadTimer timer; 
    ClassA& vector_ref;
    Logger& logger_ref;
    int id;
    int freq;
private:
    void Change();
    std::string GetInfo(); 
public:
    ClassC(int ID, int  M, ClassA& OBJ, Logger& LOG);
    ~ClassC();
};