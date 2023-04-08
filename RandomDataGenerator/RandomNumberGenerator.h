//
// Created by lukas on 01.04.2023.
//

#ifndef SDIZO_PROJECT_1_RANDOMNUMBERGENERATOR_H
#define SDIZO_PROJECT_1_RANDOMNUMBERGENERATOR_H

#include "list"

class RandomNumberGenerator {
private:
    std::list<int> randomNumberList;
public:
    RandomNumberGenerator() = default;

    ~RandomNumberGenerator() = default;

    std::list<int> *generateWithSeed(int seed, unsigned long testNumbers);

    std::list<int> *generateNonDeterministic(unsigned long testNumbers);

    int generateRandomInteger();
};

#endif //SDIZO_PROJECT_1_RANDOMNUMBERGENERATOR_H
