//
// Created by note on 11.05.17.
//

#ifndef UNTITLED_BUFFER_H
#define UNTITLED_BUFFER_H


#include <vector>
#include <iostream>
#include "Advance.h"
#include "Controller.h"
class Controller;

using namespace std;

class Queue {
public:
    Queue(int maxSize);
    bool pop();
    Advance* getResult();
    void setNext(Advance *next);
protected:
    int maxSize;
    int size = 0;
    Advance* nextEvent;
public:
    bool operator<(Queue &second);
    friend ostream& operator<<(ostream& out, Queue& buffer);

protected:
    int inPut;
    int outPut;
    int above;
};


#endif //UNTITLED_BUFFER_H
