//
// Created by lukas on 13.03.2023.
//

#include "BinaryHeap.h"
#include "iostream"
#include "list"

BinaryHeap::BinaryHeap() = default;

BinaryHeap::BinaryHeap(unsigned int size) {
    BinaryHeap::size = size;
    heapArray = new int[size];
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
        std::cout << "Unable to push data, heap is full!" << std::endl;
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

void BinaryHeap::push(int data) {
    if (sizeInUse + 1 > size) {
        std::cout << "Unable to push data, heap is full!" << std::endl;
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

int BinaryHeap::popRoot() {
    if (sizeInUse == 0) {
        std::cout << "Heap is empty!" << std::endl;
        return NULL;
    }
    int popped = heapArray[0];
    sizeInUse--;

    // Zamiana wartosci korzenia z lisciem
    heapArray[0] = heapArray[sizeInUse];

    // Naprawianie w dol
    if (sizeInUse == 0) {
        return popped;
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
    return popped;
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
    if (index >= sizeInUse || index < 0) {
        std::cout << "No element on index given!" << std::endl;
    }
    return heapArray[index];
}

// TODO: do sprawdzenia heapify
void BinaryHeap::heapify(int index) {
    try {
        int largest = index;
        int l = 2 * index + 1;
        int r = 2 * index + 2;

        // Jesli lewy potomek wiekszy
        if (l < sizeInUse && heapArray[l] > heapArray[largest]) {
            largest = l;
        }

        // jesli prawy potomek wiekszy
        if (r < sizeInUse && heapArray[r] > heapArray[largest])
            largest = r;

        // Nastepnie, jesli ktorys potomek wiekszy do rodzica
        if (largest != index && largest <= sizeInUse) {
            std::swap(heapArray[index], heapArray[largest]);
            // Wywolanie rekurencyjne
            heapify(largest);
        }
    } catch (const std::exception &e) {
        return;
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

void BinaryHeap::heapifyMoveDownFloyd(int first, int last) {
    int largest = 2 * first + 1;
    while (largest <= last) {
        if (largest + 1 >= sizeInUse) {
            break;
        }
        if (largest < last && heapArray[largest] < heapArray[largest + 1]) {
            largest++;
        }
        if (heapArray[first] < heapArray[largest]) {
            std::swap(heapArray[first], heapArray[largest]);
            first = largest;
            largest = 2 * first + 1;
        } else {
            largest = last + 1;
        }
    }
}

void BinaryHeap::loadFileDataAndHeapify(const std::list<int> &dataList) {
//    delete[] heapArray;
//    heapArray = new int[dataList.size() + sizeBuffer];

    if (size < dataList.size()) {
        std::cout << "Unable to load data, heap array is too small!" << std::endl;
        return;
    }

    if (heapArray != nullptr && size >= dataList.size()) {
        int k = 0;
        for (int const &i: dataList) {
            sizeInUse++;
            heapArray[k++] = i;
        }
    }

    for (int i = ((sizeInUse - 1) - 1) / 2; i >= 0; i--) {
        heapifyMoveDownFloyd(i, sizeInUse - 1);
    }
}

void BinaryHeap::loadFileData(const std::list<int> &dataList) {
    if (size < dataList.size()) {
        std::cout << "Unable to load data, heap array is too small!" << std::endl;
        return;
    }

    if (heapArray != nullptr && size >= dataList.size()) {
        int k = 0;
        for (int const &i: dataList) {
            sizeInUse++;
            heapArray[k++] = i;
        }
    }
}

void BinaryHeap::startHeapifyMoveDownFloyd() {
    for (int i = ((sizeInUse - 1) - 1) / 2; i >= 0; i--) {
        heapifyMoveDownFloyd(i, sizeInUse - 1);
    }
}
