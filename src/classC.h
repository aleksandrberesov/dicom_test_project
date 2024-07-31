#include "ClassA.h"
#include "ThreadTimer.cpp"

#pragma once

class ClassC{
private:
    ThreadTimer timer; 
    ClassA& vector_ref;
    int id;
    int freq;
private:
    void Change();
///    char* GetInfo(); 
public:
    ClassC(int ID, int M, ClassA& obj);
    ~ClassC();
};