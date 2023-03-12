//
// Created by lukas on 12.03.2023.
//

#ifndef SDIZO_PROJECT_1_DYNAMICARRAY_H
#define SDIZO_PROJECT_1_DYNAMICARRAY_H


class DynamicArray {
    int *pointer = nullptr;
    unsigned size = 0;

public:

    DynamicArray(int size);

    ~DynamicArray();

    void display();

    void pushFront(int data);

    void pushBack(int data);

    void pushOnIndex(int index, int val);

    void pushRandomly(int length);

    void popFront();

    void popBack();

    void popOnIndex(int index);

    void removeAll();

    int getSize();

};

#endif //SDIZO_PROJECT_1_DYNAMICARRAY_H
