//
// Created by note on 11.05.17.
//

#ifndef UNTITLED_BUFFER_H
#define UNTITLED_BUFFER_H


#include <vector>
#include <iostream>
#include "Advance.h"
#include "Line.h"
class Line;

using namespace std;

class Buffer {
public:
    Buffer(int maxSize);
    void push();
    bool pop();
    int isAbove();
    Advance* getResult();
    void setNext(Line **next);
protected:
    int maxSize;
    int size = 0;
    Line** nextEvent;
public:
    friend ostream& operator<<(ostream& out, Buffer& buffer);

protected:
    int inPut;
    int outPut;
    int above;
};


#endif //UNTITLED_BUFFER_H
