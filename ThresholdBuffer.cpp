//
// Created by note on 11.05.17.
//

#include "ThresholdBuffer.h"

ThresholdBuffer::ThresholdBuffer(int maxSize, int threshold) : maxSize(maxSize), threshold(threshold), lineOne(0), lineTwo(0) {}

bool ThresholdBuffer::isDifficult() {
    if (size >= threshold) {
        ++reserveHardware;
        return true;
    }
    else return false;
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

Advance *ThresholdBuffer::getResult(bool line) {
    push(line);
    if(!line) {
        if(!line1->isBusy() && lineOne > 0) {
            pop(line);
            return line1->makeEvent(isDifficult());
        }
    } else {
        if(!line2->isBusy() && lineTwo > 0) {
            pop(line);
            return line2->makeEvent(isDifficult());
        }
    }
    if(size > maxSize) {
        above += size - maxSize;
        size = maxSize;
    }
    return NULL;
}

bool ThresholdBuffer::watch(bool line) {
    if(line) {
        return lineTwo > 0;
    } else {
        return lineOne > 0;
    }
}

void ThresholdBuffer::setLine1(ThresholdLine *line1) {
    ThresholdBuffer::line1 = line1;
}

void ThresholdBuffer::setLine2(ThresholdLine *line2) {
    ThresholdBuffer::line2 = line2;
}

ostream &operator<<(ostream &out, ThresholdBuffer &buffer) {
    out << "inPut: " << buffer.inPut << "; outPut: " << buffer.outPut << "; above: " << buffer.above << endl;
    out << "Reserve Hardware: " << buffer.reserveHardware*100./buffer.inPut << "%";
    return out;
}

void ThresholdBuffer::setSquare(double deltaT) {
    Square += size*deltaT;
    if(size > MAX)
        MAX = size;
}

double ThresholdBuffer::getSquare() const {
    return Square;
}

int ThresholdBuffer::getMAX() const {
    return MAX;
}
