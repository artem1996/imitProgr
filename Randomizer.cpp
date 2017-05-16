//
// Created by note on 11.05.17.
//

#include "Randomizer.h"

Randomizer::Randomizer(bool randType, int min, int max) : isConstant(false), randType(randType),
                                                                           min(min), max(max) {}

Randomizer::Randomizer(int constant) : isConstant(true), randType(false),
                                                                           min(constant), max(constant) {}
int Randomizer::expRand() {
    double random = (max - min) * exp(-(double)rand()/RAND_MAX);
    return min + (int) random + (random - (int) random < 0.5 ? 0 : 1);
}

int Randomizer::linRand() {
    return min + rand() % (max - min);
}

int Randomizer::getRand() {
    if(isConstant) return min;
    else
        if(randType) return expRand();
        else return linRand();
}