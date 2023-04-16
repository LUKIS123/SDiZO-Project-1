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

void BinaryHeap::push(int data) {
    if (sizeInUse + 1 > size) {
        std::cout << "Unable to push data, heap is full!" << std::endl;
        std::cout << "Allocating new array..." << std::endl;
        int *newPointer = new int[size + 1];
        for (int i = 0; i < size; i++) {
            newPointer[i] = heapArray[i];
        }
        delete heapArray;
        heapArray = newPointer;
        size++;
    }

    sizeInUse++;
    // Naprawianie kopca w gore
    if (sizeInUse >= 1) {
        int index = sizeInUse - 1;
        int parentPosition = (index - 1) / 2;

        while (index > 0 && heapArray[parentPosition] < data) {
            heapArray[index] = heapArray[parentPosition];
            index = parentPosition;
            parentPosition = (index - 1) / 2;
        }
        // Ustawianie wartosci na wlasciwej pozycji
        heapArray[index] = data;
    } else {
        heapArray[sizeInUse - 1] = data;
    }
}

int BinaryHeap::popRoot() {
    if (sizeInUse == 0) {
        std::cout << "Heap is empty!" << std::endl;
        return NULL;
    }
    int popped = heapArray[0];
    sizeInUse--;

    if (sizeInUse == 0) {
        return popped;
    }

    int leftDescendant = 1;
    // Ostatni element kopca
    int lastDescendant = heapArray[sizeInUse];
    int currentPosition = 0;
    // Naprawianie w dol
    while (leftDescendant < sizeInUse) {
        if (leftDescendant + 1 < sizeInUse && heapArray[leftDescendant + 1] > heapArray[leftDescendant]) {
            leftDescendant++;
        }
        if (lastDescendant >= heapArray[leftDescendant]) {
            // Warunek kopca zostal spelniony
            break;
        }
        heapArray[currentPosition] = heapArray[leftDescendant];
        currentPosition = leftDescendant;
        leftDescendant = 2 * leftDescendant + 1;
    }
    // Ostatni element kopca trafia na swoje miejsce
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
        return -1;
    } else {
        return heapArray[index];
    }
}

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
    if (size < dataList.size()) {
        std::cout << "Unable to load data, heap array is too small!" << std::endl;
        return;
    }
    sizeInUse = 0;
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
    sizeInUse = 0;
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
