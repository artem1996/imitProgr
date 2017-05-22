//
// Created by note on 11.05.17.
//

#include <random>
#include "Randomizer.h"

Randomizer::Randomizer(double min, double max) : isLinear(true), min(min), max(max) {
}

Randomizer::Randomizer(bool constantOrExp, double middle) : isLinear(false), constOrExp(constantOrExp),
                                                                           min(middle), max(middle) {
    if(constantOrExp) {
        static int num = 0;
        generat = num++;
    }
}
double Randomizer::expRand() {
    static std::default_random_engine generator[2];
    static std::exponential_distribution<> distribution[2];
    if(!generated) {
        distribution[generat] = std::exponential_distribution<>(1/min);
    }
    return  distribution[generat](generator[generat]);
}

double Randomizer::linRand() {
    return min + ((double) rand()) / RAND_MAX * (max - min);
}

double Randomizer::getRand() {
    if(isLinear) return linRand();
    else
        if(constOrExp) return expRand();
        else return min;
}