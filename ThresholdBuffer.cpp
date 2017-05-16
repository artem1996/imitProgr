//
// Created by note on 11.05.17.
//

#include "ThresholdBuffer.h"

ThresholdBuffer::ThresholdBuffer(int maxSize, int threshold) : Buffer(maxSize), threshold(threshold), lineOne(0), lineTwo(0) {}

bool ThresholdBuffer::isDifficult() {
    return size >= threshold;
}

void ThresholdBuffer::push(bool line) {
    size++;
    if(line)
        lineTwo++;
    else
        lineOne++;
    inPut++;
}

bool ThresholdBuffer::pop(bool line) {
    if(line)
        if(lineTwo > 0) {
            lineTwo--;
            size--;
            outPut++;
            return true;
        } else return false;
    else
        if(lineOne > 0) {
            lineOne--;
            size--;
            outPut++;
            return true;
        } else return false;
}
