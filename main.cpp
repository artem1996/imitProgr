#include "iostream"
#include "Generator.h"
#include "Buffer.h"
#include "ThresholdBuffer.h"
#include "Line.h"
#include "ThresholdLine.h"
#define NUMOFTRANS 1000

using namespace std;

int main() {
    srand((unsigned int) time(NULL));
    int start = NUMOFTRANS;
    int tempTime = 0;
    int allTime = 0;
    Generator gen(5, 15, false);
    Buffer A(20);
    ThresholdBuffer B(25, 20);
    Line AB1(new Randomizer(20)), AB2(new Randomizer(false, 15, 25));
    ThresholdLine BC1(new Randomizer(false, 22, 28), new Randomizer(15)), BC2(new Randomizer(false, 23, 30), new Randomizer(16));
    while (start) {
        tempTime++;
        //------------------------------------------------
        if(gen.tick()) {
            A.push();
        }
        if(AB1.isAll()) {
            B.push(false);
        }
        if(AB2.isAll()) {
            B.push(true);
        }
        if(BC1.isAll())
            start--;
        if(BC2.isAll())
            start--;
        //-----------------------------------------------
        if(!AB1.isBusy() && A.pop()) {
            AB1.inProgress();
        }
        if(!AB2.isBusy() && A.pop()) {
            AB2.inProgress();
        }
        if(!BC1.isBusy()) {
            bool difficult = B.isDifficult();
            if(B.pop(false))
                BC1.tick(difficult);
        }
        if(!BC2.isBusy()) {
            bool difficult = B.isDifficult();
            if(B.pop(true))
                BC2.tick(difficult);
        }
        //------------------------------------------------
        start -= A.isAbove();
        start -= B.isAbove();
    }
    cout << "Total: " << NUMOFTRANS - start << "; Time: " << tempTime << endl;
    cout << "Generator: " << gen << endl;
    cout << "A: " << A << endl;
    cout << "AB1: " << AB1 << endl;
    cout << "AB2: " << AB2 << endl;
    cout << "B: " << B << endl;
    cout << "BC1: " << BC1 << endl;
    cout << "BC2: " << BC2 << endl;
}