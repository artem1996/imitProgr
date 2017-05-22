//
// Created by note on 11.05.17.
//

#ifndef UNTITLED_RANDOMIZER_H
#define UNTITLED_RANDOMIZER_H

#include <ctime>
#include <math.h>
#include <cstdlib>


class Randomizer {

private:
public:
    Randomizer(double constant);
    Randomizer(bool randType, double min, double max);
    double getRand();
private:
//    std::default_random_engine generator;
//    std::exponential_distribution<double> distribution;
    bool isConstant;
    bool randType;      // true = exponential, false = linear
    double min;
    double max;
    double linRand();
    double expRand();
};


#endif //UNTITLED_RANDOMIZER_H
