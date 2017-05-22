//
// Created by note on 11.05.17.
//

#ifndef UNTITLED_LINE_H
#define UNTITLED_LINE_H


#include "Randomizer.h"
#include "Advance.h"
#include "Queue.h"
#include <iostream>

using namespace std;

class Queue;

class Barber: public Advance {
public:
    Barber(Randomizer* transTime, Randomizer* diffRandTime, double dinner, double during);
    Advance* sendResult();
    Advance* makeEvent(bool difficult);
    bool isBusy();
protected:
    Randomizer* transTime;
    Randomizer* diffTransTime;
    double dinner, during;
    double dinnerStart;
    bool isDinnered = false;
};


#endif //UNTITLED_LINE_H
