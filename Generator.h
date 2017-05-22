//
// Created by note on 02.05.17.
//

#ifndef UNTITLED_GENERATOR_H
#define UNTITLED_GENERATOR_H

#include <stdlib.h>
#include "Randomizer.h"
#include <iostream>
#include "Advance.h"
#include "Buffer.h"

using namespace std;

class Generator: protected Randomizer, public Advance {
    int outPut = 0;
    int transCount;
    Buffer* nextBuf;
public:
    void setNextBuf(Buffer *nextBuf);
    Generator(double min, double max, int count, bool type);
    Generator(double constant, int count);
    Advance* sendResult();
    Advance* callBack();
    friend ostream& operator<<(ostream& out, Generator& generator);
};


#endif //UNTITLED_GENERATOR_H
