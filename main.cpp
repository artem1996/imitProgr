#include <random>
#include "iostream"
#include "Generator.h"
#include "Chanel.h"

#define NUMOFTRANS 1000
#define NUMOFCONTROLLERS 3

using namespace std;

int main() {
    srand((unsigned int) time(NULL));
    double Time = 0;
    double tempTime;
    Generator gen(5, 15, NUMOFTRANS, false);
    Queue* QChanel = new Queue(1000);
    gen.setNextBuf(QChanel);
    Chanel* chanel = new Chanel(new Randomizer(false, 7, 13), NUMOFCONTROLLERS);
    QChanel->setNext(chanel);
    chanel->setPrevBuff(QChanel);
    Queue** qControllers = new Queue*[NUMOFCONTROLLERS];
    Controller** controllers = new Controller*[NUMOFCONTROLLERS];
    for(int i = 0; i < NUMOFCONTROLLERS; i++) {
        qControllers[i] = new Queue(10);
        controllers[i] = new Controller(new Randomizer(33));
        qControllers[i] -> setNext(controllers[i]);
        controllers[i]->setPrevBuffer(qControllers[i]);
    }
    chanel->setNextBuffs(qControllers);
    std::vector<Advance*> FEC;
    FEC.push_back(&gen);
    while (FEC.size()) {
        Advance* iteration = FEC[0];
        FEC.erase(FEC.begin());
        for(int i = 0; i < FEC.size(); i++) {
            FEC[i]->decrTime(iteration->getTime());
        }
        Time += iteration->getTime();
        Advance* event = iteration->sendResult();
        if(event != NULL) {
            int i = 0;
            for(; i < FEC.size(); i++) {
                if(*event < *FEC[i]) {
                    FEC.insert(FEC.begin() + i, event);
                    break;
                }
            }
            if(i == FEC.size()) {
                FEC.push_back(event);
            }
        }
        event = iteration->callBack();
        if(event != NULL) {
            int i = 0;
            for(i = 0; i < FEC.size(); i++) {
                if(FEC[i]->getTime() > event->getTime()) {
                    FEC.insert(FEC.begin() + i, event);
                    break;
                }
            }
            if(i == FEC.size()) {
                FEC.push_back(event);
            }
        }
    }
    cout << "Total: " << NUMOFTRANS << "; Time: " << Time << endl;
    cout << "Generator: " << gen << endl;
    cout << "QChanel: " << *QChanel << endl;
    cout << "Chanel: " << *chanel << endl;
    for(int i = 0; i < NUMOFCONTROLLERS; i++) {
        cout << "QController" << i << ": " << *qControllers[i] << endl;
        cout << "Controller" << i << ": " << *controllers[i] << endl;
    }
}