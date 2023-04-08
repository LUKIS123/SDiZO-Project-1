//
// Created by lukas on 08.04.2023.
//

#ifndef SDIZO_PROJECT_1_AUTOMATICTESTS_H
#define SDIZO_PROJECT_1_AUTOMATICTESTS_H

#include "iostream"
#include "../Flow/ConsoleView.h"
#include "../Flow/ActionResult.h"
#include "../FileUtils/DataFileUtility.h"
#include "../RandomDataGenerator/RandomNumberGenerator.h"
#include "../Time/Timer.h"
#include "../DynamicArray.h"
#include "../ListBidirectional.h"
#include "../BinaryHeap.h"

class AutomaticTests {
private:
    // Data Structures
    DynamicArray *array = nullptr;
    ListBidirectional *list = nullptr;
    BinaryHeap *heap = nullptr;
public:
    RandomNumberGenerator numberGenerator;
    DataFileUtility fileUtility;
    Timer timer;
    int testNumber = 1;
    int dataBufferSize = 0;
    std::list<int> dataList;
    std::list<std::list<double>> results;

    AutomaticTests();

    AutomaticTests(const RandomNumberGenerator &numberGenerator, DataFileUtility fileUtility);

    virtual ~AutomaticTests();

    void init();

    void setTestNumber();

    void generateRandomData();

    void menu();

    void deployArrayTests();

    void deployListTests();

    void deployHeapTests();
};


#endif //SDIZO_PROJECT_1_AUTOMATICTESTS_H
