//
// Created by lukas on 29.03.2023.
//

#include "BinarySearchTree.h"
#include "iostream"

BinarySearchTree::~BinarySearchTree() {

}

void BinarySearchTree::getSize() {

}

void BinarySearchTree::display() {
    if (root == nullptr) std::cout << "Tree is empty!" << std::endl;
    else {
        std::cout << root->key << "(";
        if (root->left != nullptr) {
            printKeyRecursive(root->left);
        } else std::cout << "*";
        std::cout << ",";
        if (root->right != nullptr) {
            printKeyRecursive(root->right);
        } else std::cout << "*";
        std::cout << ")";
    }
}

void BinarySearchTree::printKeyRecursive(BinarySearchTree::BSTNode *node) {
    std::cout << node->key << "(";
    if (node->left != nullptr) {
        printKeyRecursive(node->left);
    } else std::cout << "*";
    std::cout << (",");
    if (node->right != nullptr) {
        printKeyRecursive(node->right);
    } else std::cout << "*";
    std::cout << ")";
}

void BinarySearchTree::push(int data) {
    BSTNode *newNode = new BSTNode;
    newNode->key = data;

    BSTNode *parent = nullptr;
    BSTNode *tmp = root;

    while (tmp != nullptr) {
        parent = tmp;
        if (newNode->key < tmp->key) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }

    newNode->parent = parent;
    if (parent == nullptr) {
        root = newNode;
        return;
    }

    if (newNode->key < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

//    if (parent == nullptr) {
//        root = newNode;
//        newNode->parent = nullptr;
//        return;
//    }
//    if (newNode->key < root->key) {
//
//    }
//    if (parent->right == nullptr) {
//        parent->right = newNode;
//    }
//    parent = parent->right;
}

void BinarySearchTree::pop(int data) {

}

BinarySearchTree::BSTNode *BinarySearchTree::search(int data) {
    return nullptr;
}

BinarySearchTree::BSTNode *BinarySearchTree::findSuccessor(BinarySearchTree::BSTNode *node) {
    return nullptr;
}

BinarySearchTree::BSTNode *BinarySearchTree::find_delete(int val, BinarySearchTree::BSTNode *searched) {
    return nullptr;
}

BinarySearchTree::BSTNode *BinarySearchTree::searchMin(BinarySearchTree::BSTNode *node) {
    return nullptr;
}

BinarySearchTree::BSTNode *BinarySearchTree::searchMax(BinarySearchTree::BSTNode *node) {
    return nullptr;
}
