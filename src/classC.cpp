#include <iostream>
#include <format>
#include "ClassA.h"
#include "ClassC.h"
#include "Logger.cpp"

double GetRandomValue(int min_, int max_){
    return min_ + (std::rand() % (max_ - min_ + 1)) + ((std::rand() % 100)/100);
};

ClassC::ClassC(int ID, int  M, ClassA& OBJ, Logger& LOG) :  vector_ref(OBJ),
                                                            logger_ref(LOG), 
                                                            freq(M),
                                                            id(ID)
{
    logger_ref.Log(GetInfo());
    timer.start(std::chrono::milliseconds(1000), [this](){this->Change();}); 
};

ClassC::~ClassC()
{
    timer.stop();
};

std::string ClassC::GetInfo(){
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