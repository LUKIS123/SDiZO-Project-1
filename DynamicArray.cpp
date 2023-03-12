//
// Created by lukas on 12.03.2023.
//

#include "DynamicArray.h"
#include "iostream"

DynamicArray::DynamicArray(int initSize) {
//    if (initSize == 0) {
//        return;
//    }
    pointer = new int;
//    for (int i = 0; i < initSize; i++) {
//        pointer[i] = 0;
//        size++;
//    }
}

DynamicArray::~DynamicArray() {
    delete pointer;
}

void DynamicArray::display() {
    if (size == 0) {
        std::cout << "Array is empty!" << std::endl;
    }
    for (int i = 0; i < size; i++) {
        std::cout << pointer[i] << " ";
    }
    std::cout << std::endl;
}

void DynamicArray::pushFront(int data) {
    size++;
    int *newPointer = new int[size];
    if (size > 1) {
        for (int i = 0; i < (size - 1); i++) {
            newPointer[i + 1] = pointer[i];
        }
    }
    newPointer[0] = data;
    delete pointer;
    pointer = newPointer;
}

void DynamicArray::pushBack(int data) {
    size++;
    int *newPointer = new int[size];

    if (size == 1) {
        newPointer[0] = data;
        delete pointer;
        pointer = newPointer;
        return;
    }

    int counter = 0;
    if (size > 1) {
        for (; counter < (size - 1); counter++) {
            newPointer[counter] = pointer[counter];
        }
    }

    newPointer[counter + 1] = data;
    delete pointer;
    pointer = newPointer;
}

void DynamicArray::pushOnIndex(int index, int val) {

}

// nie wiem czy to jest potrzebne
void DynamicArray::pushRandomly(int length) {

}

void DynamicArray::popFront() {

}

void DynamicArray::popBack() {

}

void DynamicArray::popOnIndex(int index) {

}

void DynamicArray::removeAll() {

}

int DynamicArray::getSize() {
    return 0;
}
