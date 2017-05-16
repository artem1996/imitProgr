//
// Created by note on 02.05.17.
//

#include "Generator.h"

Generator::Generator(int min, int max, bool type): Randomizer(type, min, max) {
}

bool Generator::tick() {
    temp--;
    if(temp <= 0) {
        temp = getRand();
        outPut++;
        return true;
    } else {
        return false;
    }
}

Generator::Generator(int constant) : Randomizer(constant) {

}

ostream &operator<<(ostream &out, Generator &generator) {
    out << "generated: " << generator.outPut;
    return out;
}
