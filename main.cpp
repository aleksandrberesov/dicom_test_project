#include <iostream>
#include <thread>
#include <random>

#include "src\ClassA.h"
#include "src\ClassB.h"
#include "src\ClassC.h"
#include "src\Lib.cpp"
#include "src\Logger.cpp"

#include "src\ThreadTimer.cpp"

int main() {

    ClassA myVector(2.2,1.0,0.7);

    for (int i = 1; i <= 5; ++i) {
        new ClassB( i,
                    GetRandomNumber(1000, 10000), 
                    GetRandomNumber(1, 200),
                    GetRandomNumber(1, 200),
                    myVector);
    }
    for (int i = 1; i <= 2; ++i) {
        new ClassC( i,
                    GetRandomNumber(10, 100),
                    myVector);
    }
  
    std::this_thread::sleep_for(std::chrono::seconds(60));
    return 0;
}