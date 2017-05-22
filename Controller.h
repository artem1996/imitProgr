//
// Created by note on 11.05.17.
//

#ifndef UNTITLED_LINE_H
#define UNTITLED_LINE_H


#include "Randomizer.h"
#include "Advance.h"
#include "Queue.h"
#include <iostream>

using namespace std;

class Queue;

class Controller: public Advance {
public:
    Controller(Randomizer* transTime);
    Advance* sendResult();
    Advance* callBack();
protected:
    Queue* prevBuffer;
public:
    void setPrevBuffer(Queue *prevBuffer);
};


#endif //UNTITLED_LINE_H
