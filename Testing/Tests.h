//
// Created by lukas on 01.04.2023.
//

#ifndef SDIZO_PROJECT_1_TESTS_H
#define SDIZO_PROJECT_1_TESTS_H

#include "iostream"
#include "list"
#include "../Time/Timer.h"
#include "../FileUtils/DataFileUtility.h"

class Tests {
protected:
    std::string headLine = "push_front, push_end, push_on_index, find_element, find_index_of, pop_front, pop_end, pop_on_index";
    std::list<double> pushFront;
    std::list<double> pushEnd;
    std::list<double> pushIndex;
    std::list<double> findByIndex;
    std::list<double> findIndexOf;
    std::list<double> popFront;
    std::list<double> popEnd;
    std::list<double> popIndex;
    std::list<double> heapifyFloyd;
    std::list<double> pushHeapOrBST;
    std::list<double> popRootHeap;
    std::list<double> popKeyHeapOrBST;
    std::list<double> findNodeBST;
    std::list<double> DSWAlgoBST;
    std::list<double> rotateRightBST;
    std::list<double> rotateLeftBST;

    unsigned pushFrontNum = 0;
    unsigned pushEndNum = 0;
    unsigned pushIndexNum = 0;
    unsigned findByIndexNum = 0;
    unsigned findIndexOfNum = 0;
    unsigned popFrontNum = 0;
    unsigned popEndNum = 0;
    unsigned popIndexNum = 0;
    unsigned heapifyFloydNum = 0;
    unsigned pushHeapOrBSTNum = 0;
    unsigned popRootHeapNum = 0;
    unsigned popKeyHeapOrBSTNum = 0;
    unsigned findNodeBSTNum = 0;
    unsigned DSWAlgoBSTNum = 0;
    unsigned rotateRightBSTNum = 0;
    unsigned rotateLeftBSTNum = 0;
public:
    int testCount = 100;
    int size = 0;
    bool tests = false;
    bool automaticTests = false;

    Tests();

    virtual ~Tests();

    void addPushFront(double result);

    void addPushEnd(double result);

    void addPushIndex(double result);

    void addFindByIndex(double result);

    void addFindIndexOf(double result);

    void addPopFront(double result);

    void addPopEnd(double result);

    void addPopIndex(double result);

    void addHeapifyFloyd(double result);

    void addPushNode(double result);

    void addPopRootHeap(double result);

    void addPopNodeWithKey(double result);

    void addFindNodeBST(double result);

    void addDSWAlgoBST(double result);

    void addRotateRightBST(double result);

    void addRotateLeftBST(double result);

    void setHeadline(std::string headLine);

    void saveResults(const std::string &fileName);

    void endTests();
};

#endif //SDIZO_PROJECT_1_TESTS_H
