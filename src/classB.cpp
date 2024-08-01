#include <iostream>
#include <format>
#include "ClassA.h"
#include "ClassB.h"
#include "Logger.cpp"

ClassB::ClassB(int ID, int N, int L1, int L2, ClassA& OBJ, Logger& LOG) :   vector_ref(OBJ), 
                                                                            logger_ref(LOG),
                                                                            freq(N), 
                                                                            range_min(L1), 
                                                                            range_max(L2),
                                                                            id(ID)
{
    last_checked_value = -1;
    if (range_min > range_max){
        int i = range_min;
        range_min = range_max;
        range_max = i;
    }
    logger_ref.Log(GetInfo());
    timer.start(std::chrono::milliseconds(1000/freq), [this](){this->Check();}); 
};

ClassB::~ClassB()
{
    timer.stop();
    logger_ref.Log("watcher stoped.");
};

std::string ClassB::GetInfo(){
    char* res = new char[100];
    sprintf(res, "wathcer %d started. frequency: %d per sec; range: %d , %d", id, freq, range_min, range_max);
    return res;
}; 
std::string ClassB::GetData(){
    char* res = new char[100];
    sprintf(res, "watcher_%d X: %.2f, Y: %.2f, Z: %.2f, Length: %.2f", id, vector_ref.getX(), vector_ref.getY(), vector_ref.getZ(), vector_ref.getLength());
    return res;
};

void ClassB::Check()
{
    double v = vector_ref.getLength();
    if ((v>=range_min) && (v<=range_max)){
        if (last_checked_value != v) {
            last_checked_value = v;
            logger_ref.Log(GetData());
        };        
    };
};