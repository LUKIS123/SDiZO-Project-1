//
// Created by lukas on 12.03.2023.
//

#ifndef SDIZO_PROJECT_1_DYNAMICARRAY_H
#define SDIZO_PROJECT_1_DYNAMICARRAY_H

#include "list"
#include "iostream"
#include "Testing/Tests.h"

class DynamicArray : public Tests {
    int *pointer = nullptr;
    unsigned size = 0;
    unsigned allocatedSize = 0;

public:
    DynamicArray();

    DynamicArray(std::list<int> intList);

    ~DynamicArray();

    void display();

    void pushFront(int data);

    void pushEnd(int data);

    void pushOnIndex(int index, int data);

    int popFront();

    int popEnd();

    int popOnIndex(int index);

    int *getByIndex(int index);

    int *getByValue(int data);

    int getIndexOf(int data);

    void removeAll();

    unsigned int getSize() const;

    void setOnIndex(int index, int data);

private:
    void reallocateSizeDown();
};

#endif //SDIZO_PROJECT_1_DYNAMICARRAY_H
