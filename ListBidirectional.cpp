//
// Created by lukas on 09.03.2023.
//

#include "ListBidirectional.h"
#include "iostream"

ListBidirectional::~ListBidirectional() {
    removeAll();
}

void ListBidirectional::loadFileData(std::list<int> &dataList) {
    removeAll();
    auto l_front = dataList.begin();
    for (int i = 0; i < dataList.size(); i++) {
        pushEnd(*l_front);
        std::advance(l_front, 1);
    }
}

void ListBidirectional::displayFromFront() {
    NodeBidirectional *current = head;
    while (current != nullptr) {
        std::cout << "[ " << current->data << " ]";
        current = current->next;
    }
    if (size == 0) {
        std::cout << "List is empty!";
    }
    std::cout << std::endl;
}

void ListBidirectional::displayFromBack() {
    NodeBidirectional *current = tail;
    while (current != nullptr) {
        std::cout << "[ " << current->data << " ]";
        current = current->prev;
    }
    if (size == 0) {
        std::cout << "List is empty!";
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
    if (index <= 0) {
        pushFront(data);
        return;
    }
    if (index >= size) {
        pushEnd(data);
        return;
    }

    NodeBidirectional *node = new NodeBidirectional;
    node->data = data;

    NodeBidirectional *current;
    if (index > (size / 2)) {
        current = tail;
        for (unsigned i = size - 1; i > index; i--) {
            current = current->prev;
            if (current == nullptr) {
                pushFront(data);
                return;
            }
        }
    } else {
        current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
            if (current == nullptr) {
                pushEnd(data);
                return;
            }
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
    if (head == nullptr) {
        std::cout << "List is empty! ";
        return NULL;
    }

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
    if (head == nullptr) {
        std::cout << "List is empty! ";
        return NULL;
    }

    size--;
    int value = tail->data;

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
    if (size == 0) {
        std::cout << "List is empty! ";
        return -1;
    }
    if (index <= 0) {
        return popFront();
    }
    if (index >= size) {
        return popEnd();
    }

    NodeBidirectional *current;
    if (index > (size / 2)) {
        current = tail;
        for (unsigned i = size - 1; i > index; i--) {
            current = current->prev;
            if (current == nullptr) {
                return popFront();
            }
        }
    } else {
        current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
            if (current == nullptr) {
                return popEnd();
            }
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
    head = nullptr;
    tail = nullptr;
}

ListBidirectional::NodeBidirectional *ListBidirectional::getByIndex(int index) {
    if (size == 0) {
        std::cout << "List is empty! ";
        return nullptr;
    }
    if (index <= 0) {
        return head;
    }
    if (index >= size - 1) {
        return tail;
    }

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

int ListBidirectional::getIndexOf(int data) {
    int index = 0;
    NodeBidirectional *current = head;
    while (current != nullptr) {
        if (current->data == data) {
            break;
        }
        current = current->next;
        index++;
    }
    if (current == nullptr) {
        return -1;
    }
    return index;
}

unsigned ListBidirectional::getSize() const {
    return size;
}

ListBidirectional::NodeBidirectional *ListBidirectional::getHead() {
    return head;
}

ListBidirectional::NodeBidirectional *ListBidirectional::getTail() {
    return tail;
}
