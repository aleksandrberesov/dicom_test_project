#include <random>

int GetRandomNumber(int min_, int max_);

int GetRandomNumber(int min_, int max_){
    return min_ + (std::rand() % (max_ - min_ + 1));
};