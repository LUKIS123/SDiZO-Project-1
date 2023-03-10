//
// Created by lukas on 09.03.2023.
//

#include "ListBidirectional.h"
#include "iostream"

ListBidirectional::~ListBidirectional() {
    removeAll();
}

void ListBidirectional::display() {
    NodeBidirectional *current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
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
    NodeBidirectional *next = current->next;
    next->prev = node;
    node->next = current->next;
    current->next = node;
    node->prev = current;
    if (node->next == nullptr) {
        tail = node;
    }
}

int ListBidirectional::popFront() {
    // do przemyslenia
    if (head == nullptr) return NULL;
    //
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
    // do przemyslenia
    if (head == nullptr) return NULL;
    //
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
    size--;
    return value;
}

void ListBidirectional::removeElement(ListBidirectional::NodeBidirectional *node) {
    if (node == nullptr) return;
    NodeBidirectional *previous = node->prev;
    NodeBidirectional *next = node->next;
    size--;
    if (previous == nullptr && next == nullptr) {
        delete node;
        head = nullptr;
        tail = nullptr;
        return;
    }
    if (node == head) {
        next->prev = nullptr;
        head = next;
        delete node;
        return;
    }
    if (node == tail) {
        previous->next = nullptr;
        tail = previous;
        delete node;
        return;
    }
    previous->next = next;
    next->prev = previous;
    delete node;
}

void ListBidirectional::removeAll() {
    NodeBidirectional *current = head;
    while (current != nullptr) {
        NodeBidirectional *temp = current;
        current = current->next;
        delete temp;
        size--;
    }
}

ListBidirectional::NodeBidirectional *ListBidirectional::getByIndex(int index) {
    NodeBidirectional *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
        if (current == nullptr) {
            return nullptr;
        }
    }
    return current;
}

ListBidirectional::NodeBidirectional *ListBidirectional::getByValue(int data) {
    NodeBidirectional *current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

unsigned ListBidirectional::getSize() {
    return size;
}

ListBidirectional::NodeBidirectional *ListBidirectional::getHead() {
    return head;
}

ListBidirectional::NodeBidirectional *ListBidirectional::getTail() {
    return tail;
}