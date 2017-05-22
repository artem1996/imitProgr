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

using namespace std;

class Generator: public Advance {
    int outPut = 0;
    int transCount;
    Queue* nextBuf;
public:
    void setNextBuf(Queue *nextBuf);
    Generator(double min, double max, int count);
    Generator(bool type, double constant, int count);
    Advance* sendResult();
    Advance* callBack();
    friend ostream& operator<<(ostream& out, Generator& generator);
};


#endif //UNTITLED_GENERATOR_H
