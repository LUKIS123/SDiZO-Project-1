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
    size++;
    NodeBidirectional *node = new NodeBidirectional;
    node->data = data;
    if (head == nullptr) {
        head = node;
        tail = node;
        return;
    }
    node->next = head;
    head->prev = node;
    head = node;
}

void ListBidirectional::pushEnd(int data) {
    size++;
    NodeBidirectional *node = new NodeBidirectional;
    node->data = data;

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
    size++;
    if (index == 0) {
        pushFront(data);
        return;
    }

    NodeBidirectional *node = new NodeBidirectional;
    node->data = data;

    NodeBidirectional *current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
        if (current == nullptr) {
            pushEnd(data);
            return;
        }
    }
    node->next = current->next;
    current->next = node;
    node->prev = current;
    if (node->next == nullptr) {
        tail = node;
    }
}

int ListBidirectional::popFront() {
    size--;
    int value = head->data;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return value;
    }

    NodeBidirectional *next = head->next;
    next->prev = nullptr;
    delete head;
    head = next;

    return value;
}

int ListBidirectional::popEnd() {
    size--;
    int value = tail->data;

    // if list has only one element
    if (tail->prev == nullptr) {
        delete tail;
        head = nullptr;
        tail = nullptr;
        return value;
    }

    NodeBidirectional *previous = tail->prev;
    previous->next = nullptr;
    delete tail;
    tail = previous;

    return value;
}

int ListBidirectional::popOnIndex(int index) {
    size--;
    if (index == 0) {
        return popFront();
    }

    // UWAGA MOZNA DODAC WARIANT, JESLI INDEX BEDZIE WIEKSZY OD SIZE/2 TO ZACZNIJ OD TAILA => TO SAMO addOnIndex
    NodeBidirectional *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
        if (current == nullptr) {
            return popEnd();
        }
    }

    int value = current->data;
    NodeBidirectional *previous = current->prev;
    NodeBidirectional *next = current->next;

    previous->next = next;
    next->prev = previous;
    if (current->next == nullptr) {
        tail = previous;
    }
    delete current;
    return value;
}

int ListBidirectional::getByIndex(int index) {
    return 0;
}

int ListBidirectional::getByValue(int data) {
    return 0;
}

void ListBidirectional::removeAll() {

}
