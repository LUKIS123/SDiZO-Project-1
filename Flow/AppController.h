//
// Created by lukas on 02.04.2023.
//

#ifndef SDIZO_PROJECT_1_APPCONTROLLER_H
#define SDIZO_PROJECT_1_APPCONTROLLER_H

#include "iostream"
#include "ConsoleView.h"
#include "ActionResult.h"
#include "../FileUtils/DataFileUtility.h"
#include "../RandomDataGenerator/RandomNumberGenerator.h"
#include "../DynamicArray.h"
#include "../ListBidirectional.h"
#include "../BinaryHeap.h"
#include "../BinarySearchTree.h"
#include "../Testing/AutomaticTests.h"
#include "../Time/Timer.h"

class AppController {
private:
    bool manualTests = false;
    // Utils
    AutomaticTests *automaticTests;
    RandomNumberGenerator numberGenerator;
    Timer timer;
    DataFileUtility fileUtility;
    std::list<int> dataBufferList;

    // Data Structures
    DynamicArray *dynamicArray;
    ListBidirectional *listBidirectional;
    BinaryHeap *heap;
    BinarySearchTree *bst;

public:
    explicit AppController();

    virtual ~AppController();

    void index();

    ActionResult::result loadFileToBufferList();

    void arrayIndex();

    ActionResult::arrayResult loadArrayWithFileData();

    ActionResult::arrayResult displayArray();

    ActionResult::arrayResult pushFrontArray();

    ActionResult::arrayResult pushBackArray();

    ActionResult::arrayResult pushOnIndexArray();

    ActionResult::arrayResult popFrontArray();

    ActionResult::arrayResult popBackArray();

    ActionResult::arrayResult popOnIndexArray();

    ActionResult::arrayResult setOnIndexArray();

    ActionResult::arrayResult displaySizeArray();

    ActionResult::arrayResult removeAllArray();

    ActionResult::arrayResult findIndexOfArray();

    ActionResult::arrayResult findByIndexArray();

    void listIndex();

    ActionResult::listResult loadListWithFileData();

    ActionResult::listResult displayListFromFront();

    ActionResult::listResult displayListFromBack();

    ActionResult::listResult pushFrontList();

    ActionResult::listResult pushBackList();

    ActionResult::listResult pushOnIndexList();

    ActionResult::listResult popFrontList();

    ActionResult::listResult popBackList();

    ActionResult::listResult popOnIndexList();

    ActionResult::listResult findByIndexList();

    ActionResult::listResult findIndexOfList();

    ActionResult::listResult removeAllList();

    ActionResult::listResult displaySizeList();

    void heapIndex();

    ActionResult::heapResult loadHeapWithFileData();

    ActionResult::heapResult displayHeap();

    void initHeap();

    ActionResult::heapResult pushHeap();

    ActionResult::heapResult popRootHeap();

    ActionResult::heapResult popElementHeap();

    ActionResult::heapResult findByIndexHeap();

    ActionResult::heapResult findIndexOfHeap();

    ActionResult::heapResult removeAllHeap();

    ActionResult::heapResult displaySizeHeap();

    void generateRandomData();

    void saveRandomDataToFIle();

    void startAutomaticTests();

    void setManualTestsStart();
};

#endif //SDIZO_PROJECT_1_APPCONTROLLER_H
