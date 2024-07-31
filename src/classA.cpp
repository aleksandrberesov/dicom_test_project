#include <cmath>
#include <thread>
#include <mutex>
#include "ClassA.h"

ClassA::ClassA(double x, double y, double z){
    setData(x, y, z);
};

ClassA::~ClassA(){

};

void ClassA::setData(double x, double y, double z){
     mtx.lock();
    point_x = x;
    point_y = y;
    point_z = z;  
    calcvectorLength();   
    mtx.unlock();
};

void ClassA::calcvectorLength(){
   vector_length = sqrt(pow(point_x, 2) + pow(point_y, 2) + pow(point_z, 2));
}; 