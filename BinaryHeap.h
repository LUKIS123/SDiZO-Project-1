//
// Created by lukas on 13.03.2023.
//

#ifndef SDIZO_PROJECT_1_BINARYHEAP_H
#define SDIZO_PROJECT_1_BINARYHEAP_H

#include "list"
#include "Testing/Tests.h"

class BinaryHeap : public Tests {
private:
    unsigned size = 0;
    int sizeInUse = 0;
    int *heapArray = nullptr;

    void fixFromTop(int index);

    void fixFromBottom(int index);

    void heapify(int index);

public:
    explicit BinaryHeap(unsigned size);

    BinaryHeap();

    virtual ~BinaryHeap();

    void display();

    void pushElement(int data);

    void popElement(int data);

    void push(int data);

    int popRoot();

    void removeAll();

    int getSize();

    int findIndexOf(int data);

    int findByIndex(int index);
    
    void pop(int data);

    void heapifyMoveDownFloyd(int first, int last);

    void loadFileDataAndHeapify(const std::list<int> &dataList);

    void loadFileData(const std::list<int> &dataList);

    void startHeapifyMoveDownFloyd();
};

#endif //SDIZO_PROJECT_1_BINARYHEAP_H
