#include <iostream>

#include <format>
#include "ClassA.h"
#include "ClassC.h"

double GetRandomValue(int min_, int max_){
    return min_ + (std::rand() % (max_ - min_ + 1));
};

ClassC::ClassC(int ID, int  M, ClassA& obj) : vector_ref(obj),
                                              freq(M),
                                              id(ID)
{
    std::cout << GetInfo() << std::endl; 
    timer.start(std::chrono::milliseconds(1000), [this](){this->Change();}); 
};

ClassC::~ClassC()
{
    timer.stop();
};

char* ClassC::GetInfo(){
    char* res = new char[100];
    sprintf(res, "changer %d started. frequency: %d per sec", id, freq);
    return res;
};

void ClassC::Change()
{
    vector_ref.setData(GetRandomValue(0, 100),
                       GetRandomValue(0, 100),
                       GetRandomValue(0, 100));

};