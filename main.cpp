#include <iostream>
#include "ListBidirectional.h"
#include "DynamicArray.h"
#include "BinaryHeap.h"

void testList() {
    ListBidirectional list = *new ListBidirectional();
    if (list.popFront() == NULL) {
        std::cout << "NULL\n";
    }

    list.pushFront(1);
    list.pushFront(22);
    list.pushFront(333);
    list.pushEnd(4444);
    list.pushEnd(5);
    list.pushEnd(6);
    list.display();

    std::cout << "==========" << std::endl;
    list.pushEnd(99);
    list.display();
    std::cout << "==========" << std::endl;
    list.pushOnIndex(1, 0);
    list.display();
    std::cout << "==========" << std::endl;
    list.popFront();
    list.display();
    std::cout << "==========" << std::endl;
    list.popEnd();
    list.display();
    std::cout << "==========" << std::endl;
    std::cout << "==========>>>>>POP ON INDEX" << std::endl;
    list.popOnIndex(1);
    list.display();
    std::cout << "==========" << std::endl;
    list.pushOnIndex(1, 55);
    list.display();
    std::cout << "==========>> head , tail" << std::endl;
    std::cout << list.getHead()->data << ", " << list.getTail()->data << std::endl;
    std::cout << "==========" << std::endl;
    std::cout << list.getByIndex(2)->data << ", " << list.getByValue(5)->data;

    std::cout << "==========" << std::endl;
    // do sprawdzenia!!!! szczegolowo
    // removeElement()
    list.removeElement(list.getByIndex(2));
    list.display();
}

void testArray() {
    DynamicArray array = *new DynamicArray(0);
    array.display();

    array.pushFront(22);
    array.pushFront(92);
    array.pushEnd(33);
    array.display();
    std::cout << "==========" << std::endl;
    array.pushOnIndex(1, 34);
    array.display();
    array.popFront(); // git
    array.display();
    array.pushOnIndex(0, 55);
    array.pushOnIndex(2, 66);
    array.display();
    std::cout << "==========" << std::endl;
    array.popEnd();
    array.display();
    std::cout << "==========>>>" << std::endl;
    array.popOnIndex(2);
    array.display();
    array.pushOnIndex(3, 88);
    array.display();
    array.popOnIndex(0);
    array.display();
    std::cout << "==========>>>" << std::endl;
    array.setOnIndex(1, 4444);
    array.display();
}

void testHeap() {
    BinaryHeap heap = *new BinaryHeap;
    heap.push(11);
    heap.push(22);
    heap.display();
    std::cout << "==========>>>\n" << std::endl;
    heap.push(33);
    heap.display();
    std::cout << "==========>>>\n" << std::endl;
    heap.push(12);
    heap.display();
    std::cout << "==========>>>\n" << std::endl;

    // zle zrobione =>
    // ALBO moze jednak dziala, tylko algorytm na usuwanie korzenia!!!
    heap.pop(11);
    heap.display();
}

int main() {
    std::cout << "Hello, World!" << std::endl;

//    testList();
//    testArray();

    testHeap();

    return 0;
}

// sortowanie kopca ->
// budujemy kopiec typu max, nastepuje zamiana szczytu kopca z ostatnim elementem, obcinamy (traktujemy jako kopiec bez tego ostatniego elementu),
// przywracana jest wlasnosc kopca zmniejszonego, i--, szczyt zamieniany z przedostatnim elemetem