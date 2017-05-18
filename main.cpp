#include "iostream"
#include "Generator.h"
#include "Queue.h"
#include "Advancer.h"
#define BUFCOUNT 3
#define TRANSCOUNT 1000

using namespace std;

template <class T>
int minim(T** a, int size) {
    int min = 0;
    for (int i = 1; i < size; ++i){
        if (*a[i] < *a[min])
            min = i;
    }
    return min;
}

int main() {
    srand((unsigned int) time(NULL));
    int start = TRANSCOUNT;
    int tempTime = 0;
    int allTime = 0;
    Generator gen(5, 15, false);
    Queue QChanel(10000);
    Advancer Chanel(new Randomizer(false, 7, 13));
    Queue** QController = new Queue*[BUFCOUNT];
    for(int i = 0; i < BUFCOUNT; i++) {
        QController[i] = new Queue(10);
    }
    Advancer** Controller = new Advancer*[BUFCOUNT];
    for(int i = 0; i < BUFCOUNT; i++) {
        Controller[i] = new Advancer(new Randomizer(33));
    }

    while (start) {
        tempTime++;
        //------------------------------------------------
        if(gen.tick()) {
            QChanel.push();
        }
        if(Chanel.isAll()) {
            QController[minim(QController, BUFCOUNT)]->push();
        }
        for (int i = 0; i < BUFCOUNT; i++){
            if(Controller[i]->isAll()){
                --start;
            }
        }
        //-----------------------------------------------
        if(!Chanel.isBusy()) {
            if(QChanel.pop())
                Chanel.tick();
        }
        for (int i = 0; i < BUFCOUNT; i++){
            if(!Controller[i]->isBusy()) {
                if(QController[i]->pop())
                    Controller[i]->tick();
            }
        }
        //------------------------------------------------
        start -= QChanel.isAbove();
        for (int i = 0; i < BUFCOUNT; i++){
            start -= QController[i]->isAbove();
        }
    }
    cout << "Total: " << TRANSCOUNT - start << "; Time: " << tempTime << endl;
    cout << "Generator: " << gen << endl;
    cout << "QChanel: " << QChanel << endl;
    cout << "Chanel: " << Chanel << endl;
    for (int i = 0; i < BUFCOUNT; i++){
        cout << "QController" << i << ": " << *QController[i] << endl; //
    }
    for (int i = 0; i < BUFCOUNT; i++){
        cout << "Controller" << i << ": " << *Controller[i] << endl; //
    }
}