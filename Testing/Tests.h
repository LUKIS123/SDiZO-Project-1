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
private:
    DataFileUtility *fileUtility;
protected:
    std::list<double> pushFront;
    std::list<double> pushEnd;
    std::list<double> pushIndex;
    std::list<double> findByIndex;
    std::list<double> findIndexOf;
    std::list<double> popFront;
    std::list<double> popEnd;
    std::list<double> popIndex;
    std::list<double> heapifyFloyd;
    std::list<double> pushHeap;
    std::list<double> popRootHeap;
    std::list<double> popKeyHeap;

    unsigned pushFrontNum = 0;
    unsigned pushEndNum = 0;
    unsigned pushIndexNum = 0;
    unsigned findByIndexNum = 0;
    unsigned findIndexOfNum = 0;
    unsigned popFrontNum = 0;
    unsigned popEndNum = 0;
    unsigned popIndexNum = 0;
    unsigned heapifyFloydNum = 0;
    unsigned pushHeapNum = 0;
    unsigned popRootHeapNum = 0;
    unsigned popKeyHeapNum = 0;
public:
    bool manualTest = false;
    int testCount = 100;
    std::string headLine = "push_front, push_end, push_on_index, find_element, find_index_of, pop_front, pop_end, pop_on_index";

    int size = 0;
    bool tests = false;

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

    void addPushHeap(double result);

    void addPopRootHeap(double result);

    void addPopKeyHeap(double result);

    void setHeadline(std::string headLine);

    void saveResults(const std::string &fileName);

    void endTests();
};

#endif //SDIZO_PROJECT_1_TESTS_H
