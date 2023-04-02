//
// Created by lukas on 01.04.2023.
//

#ifndef SDIZO_PROJECT_1_RANDOMNUMBERGENERATOR_H
#define SDIZO_PROJECT_1_RANDOMNUMBERGENERATOR_H

class RandomNumberGenerator {
private:
    unsigned TESTS = 10000000;
public:
    RandomNumberGenerator() = default;

    ~RandomNumberGenerator() = default;

    void setTests(unsigned howMany);

    void generateWithSeed(int seed) const;

    void generateNonDeterministic() const;

    [[nodiscard]] unsigned int getTests() const;
};


#endif //SDIZO_PROJECT_1_RANDOMNUMBERGENERATOR_H
