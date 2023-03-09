//
// Created by lukas on 09.03.2023.
//

#include "ListBidirectional.h"
#include "iostream"

ListBidirectional::~ListBidirectional() {
    NodeBidirectional *current = head;
    while (current != nullptr) {
        NodeBidirectional *temp = current;
        current = current->next;
        delete temp;
        size--;
    }
}

void ListBidirectional::display() {
    NodeBidirectional *current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

unsigned ListBidirectional::getSize() {
    return size;
}

void ListBidirectional::pushFront(int data) {
    NodeBidirectional *node = new NodeBidirectional;
    node->data = data;
    node->next = head;
    head = node;

    if (tail == nullptr) {
        tail = head;
    }
    size++;
}

void ListBidirectional::pushEnd(int data) {
    NodeBidirectional *node = new NodeBidirectional;
    node->data = data;
    size++;
    if (head == nullptr) {
        head = node;
        tail = node;
        return;
    }
    node->prev = tail;
    tail->next = node;
    tail = node;
}

void ListBidirectional::pushOnIndex(int index, int data) {

}

int ListBidirectional::popFront() {
    return 0;
}

int ListBidirectional::popEnd() {
    return 0;
}

int ListBidirectional::popOnIndex(int index) {
    return 0;
}

int ListBidirectional::getByIndex(int index) {
    return 0;
}

int ListBidirectional::getByValue(int data) {
    return 0;
}

void ListBidirectional::removeAll() {

}
