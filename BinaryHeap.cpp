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
    if (sizeInUse == 0) {
        std::cout << "Heap is empty!" << std::endl;
        return;
    }

    int level = 0;
    int limit = 1;
    int counter = 0;
    int spaces;
    std::cout << "Heap" << std::endl;
    std::cout << level << ":";

    spaces = sizeInUse * 0.875;
    std::cout << std::string(spaces, ' ');

    for (int i = 0; i < sizeInUse; i++) {
        std::cout << " " << heapArray[i] << ",";
        std::cout << std::string(spaces, ' ');
        counter++;
        if (counter == limit) {
            limit = limit * 2;
            counter = 0;
            level++;
            std::cout << "\n" << level << ":";

            spaces = (sizeInUse / limit);
            std::cout << std::string(spaces, ' ');
        }
    }
    std::cout << std::endl;
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

void BinaryHeap::pushElement(int data) {
    if (sizeInUse + 1 > size) {
        std::cout << "Unable to pushElement data, heap is full!" << std::endl;
        return;
    }
    heapArray[sizeInUse] = data;
    sizeInUse++;
    if (sizeInUse > 1) {
        fixFromBottom(sizeInUse - 1);
    }
}

void BinaryHeap::popElement(int data) {
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

// Do budowania kopca, dodawania elementow
void BinaryHeap::push(int data) {
    if (sizeInUse + 1 > size) {
        std::cout << "Unable to pushElement data, heap is full!" << std::endl;
        return;
    }
    heapArray[sizeInUse] = data;
    sizeInUse++;
    // Naprawianie kopca w gore
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

void BinaryHeap::popRoot() {
    if (sizeInUse == 0) {
        std::cout << "Heap is empty!" << std::endl;
        return;
    }
    sizeInUse--;
    // Zamiana wartosci korzenia z lisciem
    heapArray[0] = heapArray[sizeInUse];
    // Naprawianie w dol
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

int BinaryHeap::findByIndex(int index) {
    return heapArray[index];
}

// TODO: do testow czy cos
void BinaryHeap::pushRandomElements(int howMany) {
}

// TODO: do sprawdzenia heapify
void BinaryHeap::heapify(int index) {
    int largest = index;
    int l = 2 * index + 1;
    int r = 2 * index + 2;

    // If left child is larger than root
    if (l < sizeInUse && heapArray[l] > heapArray[largest]) {
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < sizeInUse && heapArray[r] > heapArray[largest])
        largest = r;

    // If largest is not root
    if (largest != index) {
        std::swap(heapArray[index], heapArray[largest]);
        // Recursively heapify the affected sub-tree
        heapify(largest);
    }
}

void BinaryHeap::pop(int data) {
    int index = findIndexOf(data);
    if (index == -1) {
        std::cout << "No such element to delete..." << std::endl;
        return;
    }
    sizeInUse--;
    heapArray[index] = heapArray[sizeInUse];
    heapify(index);
}
