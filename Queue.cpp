//
// Created by note on 11.05.17.
//

#include "Queue.h"

Queue::Queue(int maxSize) : maxSize(maxSize), inPut(0), outPut(0), above(0) {}

void Queue::push() {
    size++;
    inPut++;
}

bool Queue::pop() {
    if(size > 0) {
        size--;
        outPut++;
        return true;
    } else
        return false;
}

int Queue::isAbove() {
    if(size > maxSize) {
        int tempAbove = size - maxSize;
        size = maxSize;
        above += tempAbove;
        return tempAbove;
    }
    return 0;
}

ostream &operator<<(ostream &out, Queue &buffer) {
    out << "inPut: " << buffer.inPut << "; outPut: " << buffer.outPut << "; above: " << buffer.above;
    return out;
}

bool Queue::operator<(Queue &second) {
    return (this->size < second.size);
}
