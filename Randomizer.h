//
// Created by note on 11.05.17.
//

#ifndef UNTITLED_RANDOMIZER_H
#define UNTITLED_RANDOMIZER_H

#include <ctime>
#include <math.h>
#include <cstdlib>

#define LOFFSET log(RAND_MAX)

class Randomizer {

private:
public:
    Randomizer(int constant);
    Randomizer(bool randType, int min, int max);
    int getRand();
private:
    bool isConstant;
    bool randType;      // true = exponential, false = linear
    int min;
    int max;
    int linRand();
    int expRand();
};


#endif //UNTITLED_RANDOMIZER_H
