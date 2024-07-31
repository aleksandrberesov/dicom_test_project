#include <iostream>

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
    std::cout << "wathcer " << id << " started. " << "frequency: " << freq << " per sec" <<"; range: " << range_min << ", " << range_max << std::endl; 
    timer.start(std::chrono::milliseconds(1000/freq), [this](){this->Check();}); 
};

ClassB::~ClassB()
{
    timer.stop();
};

void ClassB::Check()
{
    if (last_checked_value != vector_ref.getLength()) {
        last_checked_value = vector_ref.getLength();
        //std::cout << "X: " << vector_ref.getX() << ", Y: " << vector_ref.getY() << ", Z: " << vector_ref.getZ() << ", Length: " << vector_ref.getLength() << std::endl;
    }
};