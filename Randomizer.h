#ifndef UNTITLED_RANDOMIZER_H
#define UNTITLED_RANDOMIZER_H

#include <ctime>
#include <math.h>
#include <cstdlib>

class Randomizer {

private:
public:
    Randomizer(bool constantOrExp, double middle);
    Randomizer(double min, double max);
    double getRand();
private:
    bool isLinear;
    bool constOrExp;      // true = exponential, false = const
    int generat;
    bool generated = false;
    double min;
    double max;
    double linRand();
    double expRand();
};


#endif //UNTITLED_RANDOMIZER_H