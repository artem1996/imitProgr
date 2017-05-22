//
// Created by note on 11.05.17.
//

#include "Line.h"

Line::Line(bool label, Randomizer* transTime) : transTime(transTime), label(label) {}

void Line::inProgress() {
    tempTime = transTime->getRand();
}

bool Line::isAll() {
    tempTime--;
    if(!tempTime) {
        inPut++;
        return true;
    }
    return false;
}

ostream &operator<<(ostream &out, Line &line) {
    out << "done: " << line.inPut;
    return out;
}

Advance *Line::makeEvent() {
    busy = true;
    tempTime = transTime->getRand();
    return this;
}

Advance *Line::callBack() {
    if(prevBuffer->pop()) {
        return makeEvent();
    }
    return NULL;
}

Advance *Line::sendResult() {
    busy = false;
    inPut++;
    return nextBuffer->getResult(label);
}

void Line::setPrevBuffer(Buffer *prevBuffer) {
    Line::prevBuffer = prevBuffer;
}

void Line::setNextBuffer(ThresholdBuffer *nextBuffer) {
    Line::nextBuffer = nextBuffer;
}

bool Line::isBusy() {
    return busy;
}