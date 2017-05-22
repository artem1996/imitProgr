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
    int inPut = 0;
public:
    double getTime();
    double decrTime(double minus);
    virtual Advance* sendResult();
    virtual Advance* callback();
    bool operator<(Advance& second);
    friend ostream& operator<<(ostream& out, Advance& line);
};


#endif //UNTITLED_ADVANCE_H
