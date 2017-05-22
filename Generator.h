//
// Created by note on 02.05.17.
//

#ifndef UNTITLED_GENERATOR_H
#define UNTITLED_GENERATOR_H

#include <stdlib.h>
#include "Randomizer.h"
#include <iostream>
#include "Advance.h"
#include "Queue.h"
#define THRESHOLDTIME 240

using namespace std;

class Generator: public Advance, public Randomizer {
    int outPut = 0;
    bool difficult;
public:
    Generator(double min, double max, bool type, bool difficult);
    Generator(double constant, bool difficult);
    Advance* sendResult();
    Advance* callback();
    friend ostream& operator<<(ostream& out, Generator& generator);
};


#endif //UNTITLED_GENERATOR_H
