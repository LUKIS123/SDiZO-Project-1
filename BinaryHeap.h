//
// Created by lukas on 13.03.2023.
//

#ifndef SDIZO_PROJECT_1_BINARYHEAP_H
#define SDIZO_PROJECT_1_BINARYHEAP_H

class BinaryHeap {
private:
    unsigned size = 0;
    int sizeInUse = 0;
    int *heapArray = nullptr;

    void fixFromTop(int index);

    void fixFromBottom(int index);

public:
    explicit BinaryHeap(unsigned size);

    virtual ~BinaryHeap();

    void display();

    void pushElement(int data);

    void push(int data);

    void pushRandomElements(int howMany);

    void popRoot();

    void popElement(int data);

    void removeAll();

    int getSize();

    int findIndexOf(int data);

    int findByIndex(int index);

    void heapify(int index);

    void pop(int data);
};

#endif //SDIZO_PROJECT_1_BINARYHEAP_H
