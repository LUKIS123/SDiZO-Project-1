#include <iostream>
#include "ListBidirectional.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    ListBidirectional list = *new ListBidirectional();
    list.pushFront(1);
    list.pushFront(22);
    list.pushFront(333);
    list.pushEnd(4444);
    list.pushEnd(5);
    list.pushEnd(6);
    list.display();

    return 0;
}
