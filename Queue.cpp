//
// Created by note on 11.05.17.
//

#include "Queue.h"

Queue::Queue(int maxSize) : maxSize(maxSize), inPut(0), outPut(0), above(0) {}

bool Queue::pop() {
    if(size > 0) {
        size--;
        outPut++;
        return true;
    } else
        return false;
}

ostream &operator<<(ostream &out, Queue &buffer) {
    out << "inPut: " << buffer.inPut << "; outPut: " << buffer.outPut << "; above: " << buffer.above;
    return out;
}

Advance* Queue::getResult() {
    inPut++;
    size++;
    if(!nextEvent->isBusy() && pop()) {
        return nextEvent->makeEvent();
    }
    if(size > maxSize) {
        above += size - maxSize;
        size = maxSize;
    }
    return NULL;
}

void Queue::setNext(Advance *next) {
    nextEvent = next;
}

bool Queue::operator<(Queue &second) {
    return (this->size < second.size);
}
