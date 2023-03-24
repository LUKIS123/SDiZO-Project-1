//
// Created by lukas on 13.03.2023.
//

#ifndef SDIZO_PROJECT_1_BINARYHEAP_H
#define SDIZO_PROJECT_1_BINARYHEAP_H

class BinaryHeap {
private:
    const static unsigned size = 3000;
    int sizeInUse = 0;
    int heapArray[size];

    void fixFromTop(int index);

    void fixFromBottom(int index);

public:
    BinaryHeap() = default;

    ~BinaryHeap();

    void display();

    void push(int data);

    void pushRandomElements(int howMany);

    void pop(int data);

    void removeAll();

    void getSize();

    int find(int data);
};

#endif //SDIZO_PROJECT_1_BINARYHEAP_H
