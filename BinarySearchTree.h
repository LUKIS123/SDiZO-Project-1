//
// Created by lukas on 29.03.2023.
//

#ifndef SDIZO_PROJECT_1_BINARYSEARCHTREE_H
#define SDIZO_PROJECT_1_BINARYSEARCHTREE_H

#include "Testing/Tests.h"

class BinarySearchTree : public Tests {
public:
    struct BNode {
        int key = 0;
        BNode *left = nullptr;
        BNode *right = nullptr;
        BNode *parent = nullptr;
    };

    explicit BinarySearchTree() = default;

    ~BinarySearchTree() override;

    void loadFileData(std::list<int> &dataList);

    void display();

    void display2D();

    void displayBothVariants();

    void push(int data);

    int pop(int data);

    BNode *findByValue(int data);

    unsigned int getSize();

    BNode *getRoot();

    void removeTreeDownFromNode(BNode *current);

    void removeAll();

    BNode *findSuccessor(BNode *node);

    BNode *searchMin(BNode *node);

    BNode *searchMax(BNode *node);

    void rotateRight(int data);

    void rotateRight(BNode *node);

    void rotateLeft(int data);

    void rotateLeft(BNode *node);

    void balanceTreeDSW();

    void createLinearTree();

    void createBalancedTRee();

private:
    unsigned size = 0;
    BNode *root = nullptr;

    void printKeyUtil(BinarySearchTree::BNode *node);

    void display2DUtil(BNode *node, int space);
};

#endif //SDIZO_PROJECT_1_BINARYSEARCHTREE_H
