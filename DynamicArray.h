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

    void pushEnd(int data);

    void pushOnIndex(int index, int data);

    void pushRandomData(int length);

    int popFront();

    int popEnd();

    int popOnIndex(int index);

    void removeAll();

    unsigned int getSize();

    void setOnIndex(int index, int data);
};

#endif //SDIZO_PROJECT_1_DYNAMICARRAY_H
