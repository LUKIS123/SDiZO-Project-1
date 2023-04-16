//
// Created by lukas on 12.03.2023.
//

#include "DynamicArray.h"
#include "iostream"

DynamicArray::DynamicArray() = default;

DynamicArray::DynamicArray(std::list<int> intList) {
    if (intList.size() == 0) {
        return;
    }
    allocatedSize = intList.size() + intList.size() / 8;
    pointer = new int[allocatedSize];
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
    allocatedSize = size + size / 8;
    int *newPointer = new int[allocatedSize];
    newPointer[0] = data;
    if (size > 1) {
        for (int i = 0; i < (size - 1); i++) {
            newPointer[i + 1] = pointer[i];
        }
    }
    delete pointer;
    pointer = newPointer;
}

void DynamicArray::pushEnd(int data) {
    size++;
    if (size >= allocatedSize) {
        allocatedSize = size + size / 8;
        int *newPointer = new int[allocatedSize];

        if (size == 1) {
            newPointer[0] = data;
            delete pointer;
            pointer = newPointer;
            return;
        }

        int counter = 0;
        for (; counter < size - 1; counter++) {
            newPointer[counter] = pointer[counter];
        }
        newPointer[counter] = data;
        delete pointer;
        pointer = newPointer;
    } else {
        pointer[size - 1] = data;
    }
}

void DynamicArray::pushOnIndex(int index, int data) {
    if (index >= size) {
        pushEnd(data);
    }
    if (index < 0) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    size++;
    if (size >= allocatedSize) {
        allocatedSize = size + size / 8;
        int *newPointer = new int[allocatedSize];

        if (size == 1) {
            newPointer[0] = data;
            delete pointer;
            pointer = newPointer;
            return;
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
    } else {
        int tmp = pointer[index];
        pointer[index] = data;
        for (int i = index + 1; i < size; i++) {
            int tmp2 = pointer[i];
            pointer[i] = tmp;
            tmp = tmp2;
        }
    }
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

    allocatedSize = size + size / 8;
    int *newPointer = new int[allocatedSize];
    for (int i = 0; i < size; i++) {
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

    int popped = pointer[size];
    reallocateSizeDown();
    return popped;
}

int DynamicArray::popOnIndex(int index) {
    if (size == 0) {
        std::cout << "Array is empty!" << std::endl;
        return NULL;
    }
    if (index < 0) {
        std::cout << "Invalid index!" << std::endl;
        return NULL;
    }
    if (index >= size - 1) {
        return popEnd();
    }

    size--;
    if (size == 0) {
        int popped = pointer[0];
        delete pointer;
        pointer = nullptr;
        return popped;
    }

    int popped = pointer[index];
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (counter == index) {
            counter++;
        }
        pointer[i] = pointer[counter];
        counter++;
    }

    reallocateSizeDown();
    return popped;
}

void DynamicArray::removeAll() {
    delete pointer;
    pointer = nullptr;
    size = 0;
    allocatedSize = 0;
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
    if (index < 0) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    pointer[index] = data;
}

int *DynamicArray::getByIndex(int index) {
    if (size == 0) {
        std::cout << "Array is empty!" << std::endl;
        return nullptr;
    }
    if (index >= size) {
        return &pointer[size - 1];
    }
    if (index < 0) {
        std::cout << "Invalid index!" << std::endl;
        return nullptr;
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
            break;
        }
    }
    return current;
}

int DynamicArray::getIndexOf(int data) {
    if (size == 0) {
        std::cout << "Array is empty!" << std::endl;
        return 0;
    }
    int currentIndex = -1;
    for (int i = 0; i < size; i++) {
        if (data == pointer[i]) {
            currentIndex = i;
            break;
        }
    }
    return currentIndex;
}

void DynamicArray::reallocateSizeDown() {
    if (allocatedSize >= size + size / 5) {
        allocatedSize = size + size / 8;
        int *newPointer = new int[allocatedSize];
        for (int i = 0; i < size; i++) {
            newPointer[i] = pointer[i];
        }
        delete pointer;
        pointer = newPointer;
    }
}
