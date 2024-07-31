#include <thread>
#include <mutex>

#pragma once

class Logger{
private:
    std::mutex mtx;
public:
    void Log(std::string ms){
        mtx.lock();
        std::cout << ms << std::endl; 
        mtx.unlock();
    };
};