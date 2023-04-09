//
// Created by lukas on 01.04.2023.
//

#include "RandomNumberGenerator.h"
#include "iostream"
#include "random"

std::list<int> *RandomNumberGenerator::generateWithSeed(int seed, unsigned long testNumbers) {
    int val;
    std::uniform_int_distribution<> dist(1, 1000000); // distribute results between
    std::mt19937 gen(seed);
    for (int i = 0; i < testNumbers; i++) {
        val = dist(gen);                                // pass the generator to the distribution
        randomNumberList.push_back(val);
    }
    return &randomNumberList;
}

std::list<int> *RandomNumberGenerator::generateNonDeterministic(unsigned long testNumbers) {
    int val;
    std::random_device rd;                                  // non-deterministic generator
    std::mt19937 gen(rd());                             // random engine seeded with rd()
    std::uniform_int_distribution<> dist(1, 1000000); // distribute results between
    // 1 and 1000000 inclusive
    for (int i = 0; i < testNumbers; i++) {
        val = dist(gen);                                // pass the generator to the distribution
        randomNumberList.push_back(val);
    }
    return &randomNumberList;
}

int RandomNumberGenerator::generateRandomInteger() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 1000000);
    return dist(rng);
}

