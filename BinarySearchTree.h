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

    ~BinarySearchTree() override;

    void display();

    void display2D();

    void displayBothVariants();

    void push(int data);

    int pop(int data);

    BSTNode *findByValue(int data);

    unsigned int getSize();

    BSTNode *getRoot();

    void removeTreeDownFromNode(BSTNode *current);

    void removeAll();

private:
    unsigned size = 0;
    BSTNode *root = nullptr;
    double *balancing;
    int bNumber = 0;

    void printKeyRecursive(BSTNode *node);

    void display2DUtil(BSTNode *node, int space);

    BSTNode *findSuccessor(BSTNode *node);

    BSTNode *searchMin(BSTNode *node);

    BSTNode *searchMax(BSTNode *node);
};


#endif //SDIZO_PROJECT_1_BINARYSEARCHTREE_H
