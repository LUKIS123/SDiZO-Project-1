//
// Created by lukas on 12.03.2023.
//

#include "DynamicArray.h"
#include "iostream"
#include "random"

DynamicArray::DynamicArray() = default;

DynamicArray::DynamicArray(std::list<int> intList) {
    if (intList.size() == 0) {
        return;
    }
    pointer = new int[intList.size()];
    auto l_front = intList.begin();
    for (int i = 0; i < intList.size(); i++) {
        pointer[i] = *l_front;
        size++;
        std::advance(l_front, 1);
    }
}

DynamicArray::~DynamicArray() {
    if (pointer != NULL) {
        delete pointer;
    }
}

void DynamicArray::display() {
    if (size == 0) {
        std::cout << "Array is empty!" << std::endl;
    }
    for (int i = 0; i < size; i++) {
        std::cout << "[ " << pointer[i] << " ]";
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

void DynamicArray::pushEnd(int data) {
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
        for (; counter < size - 1; counter++) {
            newPointer[counter] = pointer[counter];
        }
    }

    newPointer[counter] = data;
    delete pointer;
    pointer = newPointer;
}

void DynamicArray::pushOnIndex(int index, int data) {
    size++;
    int *newPointer = new int[size];

    if (size == 1) {
        newPointer[0] = data;
        delete pointer;
        pointer = newPointer;
        return;
    }
    if (index >= size) {
        pushEnd(data);
    }

    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (counter == index) {
            newPointer[counter] = data;
            counter++;
        }
        newPointer[counter] = pointer[i];
        counter++;
    }
    delete pointer;
    pointer = newPointer;
}

// nie wiem czy to jest potrzebne
void DynamicArray::pushRandomData(int length) {
    size = length;
    int *newPointer = new int[length];

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(-100, 100);

    for (int i = 0; i < length; i++) {
        newPointer[i] = dist(rng);
    }
    delete pointer;
    pointer = newPointer;
}

int DynamicArray::popFront() {
    if (size == 0) {
        std::cout << "Array is empty!" << std::endl;
        return NULL;
    }

    size--;
    if (size == 0) {
        int popped = pointer[0];
        delete pointer;
        pointer = nullptr;
        return popped;
    }

    int *newPointer = new int[size];
    for (int i = 0; i <= size; i++) {
        newPointer[i] = pointer[i + 1];
    }
    int popped = pointer[0];
    delete pointer;
    pointer = newPointer;
    return popped;
}

int DynamicArray::popEnd() {
    if (size == 0) {
        std::cout << "Array is empty!" << std::endl;
        return NULL;
    }

    size--;
    if (size == 0) {
        int popped = pointer[0];
        delete pointer;
        pointer = nullptr;
        return popped;
    }

    int *newPointer = new int[size];
    for (int i = 0; i < size; i++) {
        newPointer[i] = pointer[i];
    }
    int popped = pointer[size];
    delete pointer;
    pointer = newPointer;
    return popped;
}

int DynamicArray::popOnIndex(int index) {
    if (size == 0) {
        std::cout << "Array is empty!" << std::endl;
        return NULL;
    }

    size--;
    if (size == 0) {
        int popped = pointer[0];
        delete pointer;
        pointer = nullptr;
        return popped;
    }

    if (index >= size) {
        return popEnd();
    }
    int *newPointer = new int[size];
    int counter = 0;
    int popped;
    for (int i = 0; i < size + 1; i++) {
        if (i == index) {
            popped = pointer[i];
            continue;
        }
        newPointer[counter] = pointer[i];
        counter++;
    }
    delete pointer;
    pointer = newPointer;
    return popped;
}

void DynamicArray::removeAll() {
    delete pointer;
    pointer = nullptr;
    size = 0;
}

unsigned int DynamicArray::getSize() const {
    return size;
}

void DynamicArray::setOnIndex(int index, int data) {
    if (size == 0) {
        pushFront(data);
        return;
    }
    if (index >= size) {
        pushEnd(data);
        return;
    }
    for (int i = 0; i < size; i++) {
        if (i == index) {
            pointer[i] = data;
        }
    }
}

int *DynamicArray::getByIndex(int index) {
    if (size == 0) {
        std::cout << "Array is empty!" << std::endl;
        return nullptr;
    }

    if (index >= size) {
        return &pointer[size - 1];
    }
    return &pointer[index];
}

int *DynamicArray::getByValue(int data) {
    if (size == 0) {
        std::cout << "Array is empty!" << std::endl;
        return nullptr;
    }

    int *current = nullptr;
    for (int i = 0; i < size; i++) {
        if (data == pointer[i]) {
            current = &pointer[i];
        }
    }
    return current;
}

unsigned DynamicArray::getIndexOf(int data) {
    if (size == 0) {
        std::cout << "Array is empty!" << std::endl;
        return 0;
    }
    unsigned currentIndex = 0;
    for (int i = 0; i < size; i++) {
        if (data == pointer[i]) {
            currentIndex = i;
        }
    }
    return currentIndex;
}
