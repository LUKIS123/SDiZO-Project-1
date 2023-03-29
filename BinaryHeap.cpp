//
// Created by lukas on 13.03.2023.
//

#include "BinaryHeap.h"
#include "iostream"


BinaryHeap::BinaryHeap(unsigned int size) {
    BinaryHeap::size = size;
    BinaryHeap::heapArray = new int[size];
}

BinaryHeap::~BinaryHeap() {
    delete[] heapArray;
}

void BinaryHeap::display() {
    int level = 0;
    int limit = 1;
    int counter = 0;
    if (sizeInUse == 0) {
        std::cout << "Heap is empty!" << std::endl;
        return;
    }
    std::cout << level << ":";
    for (int i = 0; i < sizeInUse; i++) {
        std::cout << " " << heapArray[i];
        counter++;
        if (counter == limit) {
            limit = limit * 2;
            counter = 0;
            level++;
            std::cout << "\n" << level << ":";
        }
    }
}

void BinaryHeap::fixFromTop(int index) {
    if (sizeInUse == 0) {
        return;
    }
    int leftDescendant = 2 * index + 1;
    int largest, tmp;
    while (leftDescendant < sizeInUse || leftDescendant + 1 < sizeInUse) {
        if (leftDescendant + 1 >= sizeInUse) {
            if (heapArray[index] < heapArray[leftDescendant]) {
                tmp = heapArray[index];
                heapArray[index] = heapArray[leftDescendant];
                heapArray[leftDescendant] = tmp;
            }
            return;
        }
        if (heapArray[leftDescendant] > heapArray[leftDescendant + 1]) {
            largest = leftDescendant;
        } else {
            largest = leftDescendant + 1;
        }
        if (heapArray[largest] > heapArray[index]) {
            tmp = heapArray[largest];
            heapArray[largest] = heapArray[index];
            heapArray[index] = tmp;
            index = largest;
            leftDescendant = 2 * index + 1;
        } else {
            return;
        }
    }
}

void BinaryHeap::fixFromBottom(int index) {
    int parentPosition = (index - 1) / 2;
    int tmp;
    do {
        if (heapArray[parentPosition] < heapArray[index]) {
            tmp = heapArray[parentPosition];
            heapArray[parentPosition] = heapArray[index];
            heapArray[index] = tmp;
        }
        index = parentPosition;
        parentPosition = (index - 1) / 2;
    } while (index > 0);
}


void BinaryHeap::push(int data) {
    if (sizeInUse + 1 > size) {
        std::cout << "Unable to push data, heap is full!" << std::endl;
        return;
    }
    heapArray[sizeInUse] = data;
    sizeInUse++;
    if (sizeInUse > 1) {
        fixFromBottom(sizeInUse - 1);
    }
}

// TODO: do testow czy cos
void BinaryHeap::pushRandomElements(int howMany) {

}

void BinaryHeap::popRoot() {
    if (sizeInUse == 0) {
        std::cout << "Heap is empty!" << std::endl;
        return;
    }
    // zamiana wartosci korzenia z lisciem
    sizeInUse--;
    heapArray[0] = heapArray[sizeInUse];
    // naprawianie w dol
    if (sizeInUse == 0) {
        return;
    }
    int leftDescendant = 1;
    int lastDescendant = heapArray[sizeInUse];
    int currentPosition = 0;
    while (leftDescendant < sizeInUse) {
        if (leftDescendant + 1 < sizeInUse && heapArray[leftDescendant + 1] > heapArray[leftDescendant]) {
            leftDescendant++;
        }
        if (lastDescendant >= heapArray[leftDescendant]) {
            break;
        }
        heapArray[currentPosition] = heapArray[leftDescendant];
        currentPosition = leftDescendant;
        leftDescendant = 2 * leftDescendant + 1;
    }
    heapArray[currentPosition] = lastDescendant;
}


void BinaryHeap::pop(int data) {
    int index = findIndexOf(data);
    if (index == -1) {
        std::cout << "No such element to delete..." << std::endl;
        return;
    }
    sizeInUse--;
    heapArray[index] = heapArray[sizeInUse];
    fixFromTop(index);
    fixFromBottom(index);
}

void BinaryHeap::removeAll() {
    sizeInUse = 0;
}

int BinaryHeap::getSize() {
    return sizeInUse;
}

int BinaryHeap::findIndexOf(int data) {
    for (int i = 0; i < sizeInUse; i++) {
        if (data == heapArray[i]) {
            return i;
        }
    }
    return -1;
}

// do budowania kopca
void BinaryHeap::pushElements(int data) {
    if (sizeInUse + 1 > size) {
        std::cout << "Unable to push data, heap is full!" << std::endl;
        return;
    }
    heapArray[sizeInUse] = data;
    sizeInUse++;
    if (sizeInUse > 1) {
        int index = sizeInUse - 1;
        int parentPosition = (index - 1) / 2;
        while (index > 0 && heapArray[parentPosition] < data) {
            heapArray[index] = heapArray[parentPosition];
            index = parentPosition;
            parentPosition = (index - 1) / 2;
        }
        heapArray[index] = data;
    }
}
