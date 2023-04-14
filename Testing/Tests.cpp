//
// Created by lukas on 01.04.2023.
//

#include "Tests.h"
#include <utility>

void Tests::setHeadline(std::string newHeadLine) {
    Tests::headLine = std::move(newHeadLine);
}

void Tests::addPopNodeWithKey(double result) {
    popKeyHeapOrBST.push_back(result);
    popKeyHeapOrBSTNum++;
}

void Tests::addPopRootHeap(double result) {
    popRootHeap.push_back(result);
    popRootHeapNum++;
}

void Tests::addPushNode(double result) {
    pushHeapOrBST.push_back(result);
    pushHeapOrBSTNum++;
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

void Tests::addRotateLeftBST(double result) {
    rotateLeftBST.push_back(result);
    rotateLeftBSTNum++;
}

void Tests::addRotateRightBST(double result) {
    rotateRightBST.push_back(result);
    rotateRightBSTNum++;
}

void Tests::addDSWAlgoBST(double result) {
    DSWAlgoBST.push_back(result);
    DSWAlgoBSTNum++;
}

void Tests::addFindNodeBST(double result) {
    findNodeBST.push_back(result);
    findNodeBSTNum++;
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
    auto pushHFront = pushHeapOrBST.begin();
    auto popRFront = popRootHeap.begin();
    auto popKFront = popKeyHeapOrBST.begin();
    auto findBSTFront = findNodeBST.begin();
    auto dswAlgoFront = DSWAlgoBST.begin();
    auto rotRightFront = rotateRightBST.begin();
    auto rotLeftFront = rotateLeftBST.begin();
    for (int i = 0; i < testCount; i++) {
        std::list<double> resultList = {};

        if (pushFrontNum != 0) {
            resultList.push_back(*pushFFront);
            pushFrontNum--;
            if (pushFrontNum != 0) {
                advance(pushFFront, 1);
            }
        } else {
            resultList.push_back(-1);
        }

        if (pushEndNum != 0) {
            resultList.push_back(*pushEFront);
            pushEndNum--;
            if (pushEndNum != 0) {
                advance(pushEFront, 1);
            }
        } else {
            resultList.push_back(-1);
        }

        if (pushIndexNum != 0) {
            resultList.push_back(*pushIFront);
            pushIndexNum--;
            if (pushIndexNum != 0) {
                advance(pushIFront, 1);
            }
        } else {
            resultList.push_back(-1);
        }

        if (findByIndexNum != 0) {
            resultList.push_back(*findByIFront);
            findByIndexNum--;
            if (findByIndexNum != 0) {
                advance(findByIFront, 1);
            }
        } else {
            resultList.push_back(-1);
        }

        if (findIndexOfNum != 0) {
            resultList.push_back(*findIOfFront);
            findIndexOfNum--;
            if (findIndexOfNum != 0) {
                advance(findIOfFront, 1);
            }
        } else {
            resultList.push_back(-1);
        }

        if (popFrontNum != 0) {
            resultList.push_back(*popFFront);
            popFrontNum--;
            if (popFrontNum != 0) {
                advance(popFFront, 1);
            }
        } else {
            resultList.push_back(-1);
        }

        if (popEndNum != 0) {
            resultList.push_back(*popEFront);
            popEndNum--;
            if (popEndNum != 0) {
                advance(popEFront, 1);
            }
        } else {
            resultList.push_back(-1);
        }

        if (popIndexNum != 0) {
            resultList.push_back(*popIFront);
            popIndexNum--;
            if (popIndexNum != 0) {
                advance(popIFront, 1);
            }
        } else {
            resultList.push_back(-1);
        }

        if (heapifyFloydNum != 0) {
            resultList.push_back(*heapFFront);
            heapifyFloydNum--;
            if (heapifyFloydNum != 0) {
                advance(heapFFront, 1);
            }
        } else {
            resultList.push_back(-1);
        }

        if (pushHeapOrBSTNum != 0) {
            resultList.push_back(*pushHFront);
            pushHeapOrBSTNum--;
            if (pushHeapOrBSTNum != 0) {
                advance(pushHFront, 1);
            }
        } else {
            resultList.push_back(-1);
        }

        if (popRootHeapNum != 0) {
            resultList.push_back(*popRFront);
            popRootHeapNum--;
            if (popRootHeapNum != 0) {
                advance(popRFront, 1);
            }
        } else {
            resultList.push_back(-1);
        }

        if (popKeyHeapOrBSTNum != 0) {
            resultList.push_back(*popKFront);
            popKeyHeapOrBSTNum--;
            if (popKeyHeapOrBSTNum != 0) {
                advance(popKFront, 1);
            }
        } else {
            resultList.push_back(-1);
        }

        if (findNodeBSTNum != 0) {
            resultList.push_back(*findBSTFront);
            findNodeBSTNum--;
            if (findNodeBSTNum != 0) {
                advance(findBSTFront, 1);
            }
        } else {
            resultList.push_back(-1);
        }

        if (DSWAlgoBSTNum != 0) {
            resultList.push_back(*dswAlgoFront);
            DSWAlgoBSTNum--;
            if (DSWAlgoBSTNum != 0) {
                advance(dswAlgoFront, 1);
            }
        } else {
            resultList.push_back(-1);
        }

        if (rotateRightBSTNum != 0) {
            resultList.push_back(*rotRightFront);
            rotateRightBSTNum--;
            if (rotateRightBSTNum != 0) {
                advance(rotRightFront, 1);
            }
        } else {
            resultList.push_back(-1);
        }

        if (rotateLeftBSTNum != 0) {
            resultList.push_back(*rotLeftFront);
            rotateLeftBSTNum--;
            if (rotateLeftBSTNum != 0) {
                advance(rotLeftFront, 1);
            }
        } else {
            resultList.push_back(-1);
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
    pushHeapOrBST.clear();
    popRootHeap.clear();
    popKeyHeapOrBST.clear();
}

Tests::Tests() = default;

Tests::~Tests() = default;
