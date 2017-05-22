//
// Created by note on 11.05.17.
//

#include <random>
#include "Randomizer.h"

Randomizer::Randomizer(bool randType, double min, double max) : isConstant(false), randType(randType),
                                                                           min(min), max(max) {
}

Randomizer::Randomizer(double constant) : isConstant(true), randType(false),
                                                                           min(constant), max(constant) {}
double Randomizer::expRand() {
    double random = exp(-(double)rand()/RAND_MAX);
    return random;
}

double Randomizer::linRand() {
    return min + ((double) rand()) / RAND_MAX * (max - min);
}

double Randomizer::getRand() {
    if(isConstant) return min;
    else
        if(randType) return expRand();
        else return linRand();
}