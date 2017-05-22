
#ifndef UNTITLED_THRESHOLDLINE_H
#define UNTITLED_THRESHOLDLINE_H

#include <iostream>
#include "Advance.h"
#include "Randomizer.h"
#include "ThresholdBuffer.h"

using namespace std;

class ThresholdBuffer;

class ThresholdLine: public Advance {
    Randomizer* boostTime;
    Randomizer* transTime;
    ThresholdBuffer* prevBuff;
    bool label;
    int inPut = 0;
public:
    void setPrevBuff(ThresholdBuffer *prevBuff);
    ThresholdLine(bool label, Randomizer* transTime, Randomizer* boostTime);
    void tick(bool);
    Advance* sendResult();
    Advance* callBack();
    Advance* makeEvent(bool Line);
    friend ostream& operator<<(ostream& out, ThresholdLine& line);
};


#endif //UNTITLED_THRESHOLDLINE_H
