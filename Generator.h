//
// Created by note on 02.05.17.
//

#ifndef UNTITLED_GENERATOR_H
#define UNTITLED_GENERATOR_H

#include <stdlib.h>
#include "Randomizer.h"
#include <iostream>

using namespace std;

class Generator: protected Randomizer {
    int temp = 0;
    int outPut = 0;
public:
    Generator(int min, int max, bool type);
    Generator(int constant);
    bool tick();
    friend ostream& operator<<(ostream& out, Generator& generator);
};


#endif //UNTITLED_GENERATOR_H
