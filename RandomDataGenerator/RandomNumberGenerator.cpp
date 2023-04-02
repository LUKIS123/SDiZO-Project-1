//
// Created by lukas on 01.04.2023.
//

#include "RandomNumberGenerator.h"
#include "iostream"
#include "random"

void RandomNumberGenerator::generateWithSeed(int seed) const {
    int val, min, max;
    std::uniform_int_distribution<> dist(1, 1000000); // distribute results between
    std::mt19937 gen(seed);
    min = INT_MAX;
    max = 0;
    // 1 and 1000000 inclusive
    for (int i = 0; i < TESTS; i++) {
        val = dist(gen);                                // pass the generator to the distribution
        if (val < min)
            min = val;
        if (val > max)
            max = val;
    }
    std::cout << "min = " << min << " max = " << max << std::endl;
    system("PAUSE");
}

void RandomNumberGenerator::generateNonDeterministic() const {
    int val, min, max;
    std::random_device rd;                                  // non-deterministic generator
    std::mt19937 gen(rd());                             // random engine seeded with rd()
    std::uniform_int_distribution<> dist(1, 1000000); // distribute results between
    // 1 and 1000000 inclusive
    min = INT_MAX;
    max = 0;
    for (int i = 0; i < TESTS; i++) {
        val = dist(gen);                                // pass the generator to the distribution
        if (val < min)
            min = val;
        if (val > max)
            max = val;
    }
    std::cout << "min = " << min << " max = " << max << std::endl;
    system("PAUSE");
}

void RandomNumberGenerator::setTests(unsigned int howMany) {
    TESTS = howMany;
}

unsigned int RandomNumberGenerator::getTests() const {
    return TESTS;
}
