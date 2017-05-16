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

bool Buffer::watch() {
    return size > 0;
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

int Buffer::getInPut() const {
    return inPut;
}

int Buffer::getOutPut() const {
    return outPut;
}

int Buffer::getAbove() const {
    return above;
}

ostream &operator<<(ostream &out, Buffer &buffer) {
    out << "inPut: " << buffer.inPut << "; outPut: " << buffer.outPut << "; above: " << buffer.above;
    return out;
}
