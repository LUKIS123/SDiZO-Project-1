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
    std::cout << "==========>>>>>" << std::endl;
    list.popOnIndex(1);
    list.display();
    std::cout << "==========" << std::endl;

    std::cout << "==========" << std::endl;

    return 0;
}
