//
// Created by note on 11.05.17.
//

#ifndef UNTITLED_THRESHOLDBUFFER_H
#define UNTITLED_THRESHOLDBUFFER_H

#include <iostream>
#include "Buffer.h"
#include "ThresholdLine.h"

using namespace std;
class ThresholdLine;

class ThresholdBuffer {
    int threshold;
    int lineOne;
    int lineTwo;
    int maxSize;
    int size = 0;
    int inPut = 0;
    int outPut = 0;
    int above;
    double Square = 0;
    int MAX = 0;
    int reserveHardware = 0;
public:
    int getMAX() const;

public:
    double getSquare() const;

public:
    void setLine1(ThresholdLine *line1);
    void setLine2(ThresholdLine *line2);
private:
    ThresholdLine *line1, *line2;
public:
    ThresholdBuffer(int maxSize, int threshold);
    bool isDifficult();
    void push(bool line);
    bool pop(bool line);
    bool watch(bool line);
    Advance* getResult(bool);
    void setSquare(double);
    friend ostream& operator<<(ostream& out, ThresholdBuffer& buffer);
};


#endif //UNTITLED_THRESHOLDBUFFER_H
