//
// Created by lukas on 13.03.2023.
//

#include "BinaryHeap.h"
#include "iostream"

BinaryHeap::~BinaryHeap() {
    // delete[] &heapArray;
}

// do zmian, pozyczone z internetu
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

// chyba zle
void BinaryHeap::fixFromTop(int index) {
    if (sizeInUse == 0) {
        return;
    }
    int leftDescendant = 2 * index + 1;
    // int rightDescendant = 2 * index + 2;
    int lastDescendant = heapArray[sizeInUse];
    // int tmp;
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

// chyba dziala
void BinaryHeap::fixFromBottom(int index) {
    int parentPosition = (index - 1) / 2;
    int tmp;
    while (index > 0) {
        if (heapArray[parentPosition] < heapArray[index]) {
            tmp = heapArray[parentPosition];
            heapArray[parentPosition] = heapArray[index];
            heapArray[index] = tmp;
        }
        index = parentPosition;
        parentPosition = (index - 1) / 2;
    }
}

// chyba dziala
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

void BinaryHeap::pushRandomElements(int howMany) {

}

void BinaryHeap::pop(int data) {
    // do zrobienia znajdywanie czy element istnieje => funckja find
    int index = find(data);
    if (index == -1) {
        std::cout << "Nie ma takiego elementu" << std::endl;
        return;
    }
    sizeInUse--;
    heapArray[index] = heapArray[sizeInUse];
    fixFromTop(index);
    // fixFromBottom(index);
}

void BinaryHeap::removeAll() {

}

void BinaryHeap::getSize() {

}

int BinaryHeap::find(int data) {
    if (sizeInUse == 0) {
        return -1;
    }
    for (int i = 0; i < sizeInUse; i++) {
        if (data == heapArray[i]) {
            return i;
        }
    }
    return 0;
}
