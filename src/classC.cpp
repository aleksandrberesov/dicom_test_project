#include <iostream>

#include <format>
#include "ClassA.h"
#include "ClassC.h"

ClassC::ClassC(int ID, int  M, ClassA& obj) : vector_ref(obj),
                                      freq(M),
                                      id(ID)
{
    std::cout << "changer " << id << " started. " << "frequency: " << freq << " per sec" << std::endl; 
    timer.start(std::chrono::milliseconds(1000), [this](){this->Change();}); 
};

ClassC::~ClassC()
{
    timer.stop();
};

void ClassC::Change()
{
    vector_ref.setData(1,2,3);

};