//
// Created by lukas on 29.03.2023.
//

#ifndef SDIZO_PROJECT_1_BINARYSEARCHTREE_H
#define SDIZO_PROJECT_1_BINARYSEARCHTREE_H

#include "Testing/Tests.h"

class BinarySearchTree : public Tests {
public:
    struct BSTNode {
        int key = 0;
        BSTNode *left = nullptr;
        BSTNode *right = nullptr;
        BSTNode *parent = nullptr;
    };

    explicit BinarySearchTree() = default;

    virtual ~BinarySearchTree();

    // dodawanie, usuwanie i wyszukiwanie elementów
    void display();

    void push(int data);

    void pop(int data);

    BSTNode *search(int data);

    void getSize();

private:
    int size = 0;
    BSTNode *root = nullptr;

    BSTNode *find_delete(int val, BSTNode *searched);

    void printKeyRecursive(BSTNode *node);

    BSTNode *findSuccessor(BSTNode *node);

    BSTNode *searchMin(BSTNode *node);

    BSTNode *searchMax(BSTNode *node);
};


#endif //SDIZO_PROJECT_1_BINARYSEARCHTREE_H
