//
// Created by note on 11.05.17.
//

#ifndef UNTITLED_LINE_H
#define UNTITLED_LINE_H


#include "Randomizer.h"
#include "Advance.h"
#include "ThresholdBuffer.h"
#include <iostream>

using namespace std;

class Buffer;
class ThresholdBuffer;

class Line: public Advance {
public:
    Line(bool label, Randomizer* transTime);
    void inProgress();
    bool isAll();
    Advance* sendResult();
    Advance* callBack();
    Advance* makeEvent();
    bool isBusy();
    friend ostream& operator<<(ostream& out, Line& line);
protected:
    Randomizer* transTime;
    int inPut = 0;
    bool label;
    bool busy = false;
    Buffer* prevBuffer;
public:
    void setPrevBuffer(Buffer *prevBuffer);

    void setNextBuffer(ThresholdBuffer *nextBuffer);

protected:
    ThresholdBuffer* nextBuffer;
};


#endif //UNTITLED_LINE_H
