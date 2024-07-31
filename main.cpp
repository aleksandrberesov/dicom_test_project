#include <iostream>
#include <thread>
#include <random>

#include "src\ClassA.h"
#include "src\ClassB.h"
#include "src\ClassC.h"
#include "src\Logger.cpp"

int GetRandomNumber(int min_, int max_){
    return min_ + (std::rand() % (max_ - min_ + 1));
};

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));    

    Logger myLogger;
    ClassA myVector(0,0,0);

    for (int i = 1; i <= 5; ++i) {
        new ClassB( i,
                    GetRandomNumber(1000, 10000), 
                    GetRandomNumber(1, 200),
                    GetRandomNumber(1, 200),
                    myVector, 
                    myLogger);
    }

    for (int i = 1; i <= 2; ++i) {
        new ClassC( i,
                    GetRandomNumber(10, 100),
                    myVector,
                    myLogger);
    }
  
    std::this_thread::sleep_for(std::chrono::seconds(60));
    return 0;
}