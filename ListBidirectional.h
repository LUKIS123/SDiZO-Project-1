#ifndef SDIZO_PROJECT_1_LISTBIDIRECTIONAL_H
#define SDIZO_PROJECT_1_LISTBIDIRECTIONAL_H

class ListBidirectional {
public:
    struct NodeBidirectional {
        int data;
        NodeBidirectional *prev = nullptr;
        NodeBidirectional *next = nullptr;
    };

    ListBidirectional() = default;

    ~ListBidirectional();

    void display();

    void pushFront(int data);

    void pushEnd(int data);

    void pushOnIndex(int index, int data);

    int popFront();

    int popEnd();

    int popOnIndex(int index);

    int getByIndex(int index);

    int getByValue(int data);

    void removeAll();

    unsigned getSize();

    NodeBidirectional *getHead();

    NodeBidirectional *getTail();

private:
    NodeBidirectional *head = nullptr;
    NodeBidirectional *tail = nullptr;
    unsigned size = 0;
};

#endif //SDIZO_PROJECT_1_LISTBIDIRECTIONAL_H
