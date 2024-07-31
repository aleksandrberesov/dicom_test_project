#include <thread>
#include <mutex>

#pragma once

class ClassA{
private:
    double point_x;
    double point_y;
    double point_z;   
    double vector_length; 
    std::mutex mtx;
protected:
    void calcvectorLength();
public:
    ClassA(double x, double y, double z);
    ~ClassA();
    void setData(double x, double y, double z);
    double getLength() const { return vector_length; }
    double getX() const { return point_x; }
    double getY() const { return point_y; }
    double getZ() const { return point_z; }
};