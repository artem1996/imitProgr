//
// Created by note on 11.05.17.
//

#include "Transfer.h"

Transfer::Transfer(double probability) : probability(probability) {}

bool Transfer::tick() {
    temp += probability;
    bool answer = temp >= 1;
    temp = temp - (int) temp;
    return answer;
}
