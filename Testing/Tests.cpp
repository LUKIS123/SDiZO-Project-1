//
// Created by lukas on 01.04.2023.
//

#include "Tests.h"
#include <utility>

void Tests::setHeadline(std::string newHeadLine) {
    Tests::headLine = std::move(newHeadLine);
}

void Tests::addPopKeyHeap(double result) {
    popKeyHeap.push_back(result);
    popKeyHeapNum++;
}

void Tests::addPopRootHeap(double result) {
    popRootHeap.push_back(result);
    popRootHeapNum++;
}

void Tests::addPushHeap(double result) {
    pushHeap.push_back(result);
    pushHeapNum++;
}

void Tests::addHeapifyFloyd(double result) {
    heapifyFloyd.push_back(result);
    heapifyFloydNum++;
}

void Tests::addPopIndex(double result) {
    popIndex.push_back(result);
    popIndexNum++;
}

void Tests::addPopEnd(double result) {
    popEnd.push_back(result);
    popEndNum++;
}

void Tests::addPopFront(double result) {
    popFront.push_back(result);
    popFrontNum++;
}

void Tests::addFindIndexOf(double result) {
    findIndexOf.push_back(result);
    findIndexOfNum++;
}

void Tests::addFindByIndex(double result) {
    findByIndex.push_back(result);
    findByIndexNum++;
}

void Tests::addPushIndex(double result) {
    pushIndex.push_back(result);
    pushIndexNum++;
}

void Tests::addPushEnd(double result) {
    pushEnd.push_back(result);
    pushEndNum++;
}

void Tests::addPushFront(double result) {
    pushFront.push_back(result);
    pushFrontNum++;
}

void Tests::saveResults(const std::string &fileName) {
    DataFileUtility::saveResultsHeadline(fileName, headLine);
    auto pushFFront = pushFront.begin();
    auto pushEFront = pushEnd.begin();
    auto pushIFront = pushEnd.begin();
    auto findByIFront = findByIndex.begin();
    auto findIOfFront = findIndexOf.begin();
    auto popFFront = popFront.begin();
    auto popEFront = popEnd.begin();
    auto popIFront = popIndex.begin();
    auto heapFFront = heapifyFloyd.begin();
    auto pushHFront = pushHeap.begin();
    auto popRFront = popRootHeap.begin();
    auto popKFront = popKeyHeap.begin();
    for (int i = 0; i < testCount; i++) {
        std::list<double> resultList = {};

        if (pushFrontNum != 0) {
            resultList.push_back(*pushFFront);
            pushFrontNum--;
            if (pushFrontNum != 0) {
                advance(pushFFront, 1);
            }
        } else {
            resultList.push_back(0);
        }

        if (pushEndNum != 0) {
            resultList.push_back(*pushEFront);
            pushEndNum--;
            if (pushEndNum != 0) {
                advance(pushEFront, 1);
            }
        } else {
            resultList.push_back(0);
        }

        if (pushIndexNum != 0) {
            resultList.push_back(*pushIFront);
            pushIndexNum--;
            if (pushIndexNum != 0) {
                advance(pushIFront, 1);
            }
        } else {
            resultList.push_back(0);
        }

        if (findByIndexNum != 0) {
            resultList.push_back(*findByIFront);
            findByIndexNum--;
            if (findByIndexNum != 0) {
                advance(findByIFront, 1);
            }
        } else {
            resultList.push_back(0);
        }

        if (findIndexOfNum != 0) {
            resultList.push_back(*findIOfFront);
            findIndexOfNum--;
            if (findIndexOfNum != 0) {
                advance(findIOfFront, 1);
            }
        } else {
            resultList.push_back(0);
        }

        if (popFrontNum != 0) {
            resultList.push_back(*popFFront);
            popFrontNum--;
            if (popFrontNum != 0) {
                advance(popFFront, 1);
            }
        } else {
            resultList.push_back(0);
        }

        if (popEndNum != 0) {
            resultList.push_back(*popEFront);
            popEndNum--;
            if (popEndNum != 0) {
                advance(popEFront, 1);
            }
        } else {
            resultList.push_back(0);
        }

        if (popIndexNum != 0) {
            resultList.push_back(*popIFront);
            popIndexNum--;
            if (popIndexNum != 0) {
                advance(popIFront, 1);
            }
        } else {
            resultList.push_back(0);
        }

        if (heapifyFloydNum != 0) {
            resultList.push_back(*heapFFront);
            heapifyFloydNum--;
            if (heapifyFloydNum != 0) {
                advance(heapFFront, 1);
            }
        } else {
            resultList.push_back(0);
        }

        if (pushHeapNum != 0) {
            resultList.push_back(*pushHFront);
            pushHeapNum--;
            if (pushHeapNum != 0) {
                advance(pushHFront, 1);
            }
        } else {
            resultList.push_back(0);
        }

        if (popRootHeapNum != 0) {
            resultList.push_back(*popRFront);
            popRootHeapNum--;
            if (popRootHeapNum != 0) {
                advance(popRFront, 1);
            }
        } else {
            resultList.push_back(0);
        }

        if (popKeyHeapNum != 0) {
            resultList.push_back(*popKFront);
            popKeyHeapNum--;
            if (popKeyHeapNum != 0) {
                advance(popKFront, 1);
            }
        } else {
            resultList.push_back(0);
        }

        // Saving data...
        DataFileUtility::saveTimerResults(fileName, resultList);
    }
    endTests();
}

void Tests::endTests() {
    pushFront.clear();
    pushEnd.clear();
    pushIndex.clear();
    findByIndex.clear();
    findIndexOf.clear();
    popFront.clear();
    popEnd.clear();
    popIndex.clear();
    heapifyFloyd.clear();
    pushHeap.clear();
    popRootHeap.clear();
    popKeyHeap.clear();
}

Tests::Tests() {
    fileUtility = new DataFileUtility();
}

Tests::~Tests() = default;
