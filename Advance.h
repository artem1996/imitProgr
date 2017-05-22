//
// Created by note on 18.05.17.
//


#ifndef UNTITLED_ADVANCE_H
#define UNTITLED_ADVANCE_H

#include <iostream>
#include "Randomizer.h"

using namespace std;

class Advance {
protected:
    double tempTime = 0;
    bool busy = false;
    Randomizer * randomizer;
    int inPut = 0;
public:
    Advance(Randomizer *randomizer);
    double getTime();
    double decrTime(double minus);
    virtual Advance* sendResult();
    virtual Advance* callBack();
    Advance* makeEvent();
    bool operator<(Advance& second);
    friend ostream& operator<<(ostream& out, Advance& line);
    bool isBusy();
};


#endif //UNTITLED_ADVANCE_H
