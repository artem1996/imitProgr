//
// Created by note on 11.05.17.
//

#ifndef UNTITLED_BUFFER_H
#define UNTITLED_BUFFER_H


#include <vector>
#include <iostream>

using namespace std;

class Buffer {
public:
    Buffer(int maxSize);
    void push();
    bool pop();
    int isAbove();
protected:
    int maxSize;
    int size = 0;
public:
    friend ostream& operator<<(ostream& out, Buffer& buffer);

protected:
    int inPut;
    int outPut;
    int above;
};


#endif //UNTITLED_BUFFER_H
