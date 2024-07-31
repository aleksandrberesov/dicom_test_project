#include <iostream>
#include <format>
#include "ClassA.h"
#include "ClassB.h"

ClassB::ClassB(int ID, int N, int L1, int L2, ClassA& obj) : vector_ref(obj), 
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
    std::cout << GetInfo() << std::endl; 
    timer.start(std::chrono::milliseconds(1000/freq), [this](){this->Check();}); 
};

ClassB::~ClassB()
{
    timer.stop();
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
    if (last_checked_value != vector_ref.getLength()) {
        last_checked_value = vector_ref.getLength();
        //std::cout << GetData() << " ,last: " << last_checked_value << std::endl;
        //std::cout << "X: " << vector_ref.getX() << ", Y: " << vector_ref.getY() << ", Z: " << vector_ref.getZ() << ", Length: " << vector_ref.getLength() << std::endl;
    }
};