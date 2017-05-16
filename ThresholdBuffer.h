//
// Created by note on 11.05.17.
//

#ifndef UNTITLED_THRESHOLDBUFFER_H
#define UNTITLED_THRESHOLDBUFFER_H


#include "Buffer.h"

class ThresholdBuffer: public Buffer {
    int threshold;
    int lineOne;
    int lineTwo;
public:
    ThresholdBuffer(int maxSize, int threshold);
    bool isDifficult();
    void push(bool line);
    bool pop(bool line);
};


#endif //UNTITLED_THRESHOLDBUFFER_H
