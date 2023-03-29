#ifndef SDIZO_PROJECT_1_LISTBIDIRECTIONAL_H
#define SDIZO_PROJECT_1_LISTBIDIRECTIONAL_H

class ListBidirectional {
public:
    struct NodeBidirectional {
        int data = 0;
        NodeBidirectional *prev = nullptr;
        NodeBidirectional *next = nullptr;
    };

    ListBidirectional() = default;

    ~ListBidirectional();

    void displayFromFront();

    void displayFromBack();

    void pushFront(int data);

    void pushEnd(int data);

    void pushOnIndex(int index, int data);

    int popFront();

    int popEnd();

    int popOnIndex(int index);

    void removeElement(NodeBidirectional *node);

    NodeBidirectional *getByIndex(int index);

    NodeBidirectional *getByValue(int data);

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
