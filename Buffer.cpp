//
// Created by note on 11.05.17.
//

#include "Buffer.h"

Buffer::Buffer(int maxSize) : maxSize(maxSize), inPut(0), outPut(0), above(0) {}

void Buffer::push() {
    size++;
    inPut++;
}

bool Buffer::pop() {
    if(size > 0) {
        size--;
        outPut++;
        return true;
    } else
        return false;
}


int Buffer::isAbove() {
    if(size > maxSize) {
        int tempAbove = size - maxSize;
        size = maxSize;
        above += tempAbove;
        return tempAbove;
    }
    return 0;
}

ostream &operator<<(ostream &out, Buffer &buffer) {
    out << "inPut: " << buffer.inPut << "; outPut: " << buffer.outPut << "; above: " << buffer.above;
    return out;
}

Advance* Buffer::getResult() {
    inPut++;
    size++;
    if(!nextEvent[0]->isBusy() && pop()) {
        return nextEvent[0]->makeEvent();
    }
    if(!nextEvent[1]->isBusy() && pop()) {
        return nextEvent[1]->makeEvent();
    }
    if(size > maxSize) {
        above += size - maxSize;
        size = maxSize;
    }
    return NULL;
}

void Buffer::setNext(Line **next) {
    nextEvent = next;
}
