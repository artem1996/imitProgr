//
// Created by note on 11.05.17.
//

#ifndef UNTITLED_BUFFER_H
#define UNTITLED_BUFFER_H


#include <vector>
#include <iostream>

using namespace std;

class Queue {
public:
    Queue(int maxSize);
    void push();
    bool pop();
    int isAbove();
    bool operator<(Queue& second);
protected:
    int maxSize;
    int size = 0;
public:
    friend ostream& operator<<(ostream& out, Queue& buffer);

protected:
    int inPut;
    int outPut;
    int above;
};


#endif //UNTITLED_BUFFER_H
