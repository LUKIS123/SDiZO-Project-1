//
// Created by lukas on 29.03.2023.
//

#include "BinarySearchTree.h"
#include "iostream"

#define COUNT 10

BinarySearchTree::~BinarySearchTree() {
    removeAll();
}

void BinarySearchTree::loadFileData(std::list<int> &dataList) {
    removeAll();
    auto l_front = dataList.begin();
    for (int i = 0; i < dataList.size(); i++) {
        push(*l_front);
        std::advance(l_front, 1);
    }
}

BinarySearchTree::BSTNode *BinarySearchTree::getRoot() {
    return root;
}

unsigned int BinarySearchTree::getSize() {
    return size;
}

void BinarySearchTree::displayBothVariants() {
    display();
    std::cout << std::endl;
    display2D();
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

void BinarySearchTree::display2D() {
    display2DUtil(root, 0);
}

void BinarySearchTree::display2DUtil(BSTNode *node, int space) {
    if (node == nullptr) {
        return;
    }

    space += COUNT;

    display2DUtil(node->right, space);

    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << node->key << "\n";

    display2DUtil(node->left, space);
}

void BinarySearchTree::push(int data) {
    size++;
    BSTNode *newNode = new BSTNode;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->key = data;

    BSTNode *tmp = root;

    if (tmp == nullptr) {
        root = newNode;
        newNode->parent = tmp;
        return;
    }

    while (true) {
        if (data < tmp->key) {

            if (tmp->left == nullptr) {
                tmp->left = newNode;
                break;
            } else {
                tmp = tmp->left;
            }

        } else {

            if (tmp->right == nullptr) {
                tmp->right = newNode;
                break;
            } else {
                tmp = tmp->right;
            }

        }

    }
    newNode->parent = tmp;
}

int BinarySearchTree::pop(int data) {
    BSTNode *foundToDelete = findByValue(data);
    if (foundToDelete == nullptr) {
        return NULL;
    }

    BSTNode *Y, *X;
    // Jesli wezel jest lisciem lub ma tylko jednego potomka, Y wskazuje na wezel
    // W przeciwnym wypadku Y wskazuje na nastepnik wezla
    if (foundToDelete->left == nullptr || foundToDelete->right == nullptr) {
        Y = foundToDelete;
    } else {
        Y = findSuccessor(foundToDelete);
    }

    // X wskazuje na syna Y albo nullptr
    if (Y->left != nullptr) {
        X = Y->left;
    } else {
        X = Y->right;
    }

    // Jesli Y posiada potomka, usun Y z drzewa
    if (X != nullptr) {
        X->parent = Y->parent;
    }

    // Y zostaje zastapione przez X
    if (Y->parent == nullptr) {     // Y jest korzeniem
        root = X;
    } else if (Y == Y->parent->left) {
        Y->parent->left = X;
    } else {
        Y->parent->right = X;
    }

    if (Y != foundToDelete) {
        // Zastepowanie klucza wezla do usuniecia
        foundToDelete->key = Y->key;
    }

    int popped = Y->key;
    delete Y;
    return popped;
}

BinarySearchTree::BSTNode *BinarySearchTree::findByValue(int data) {
    BSTNode *current = root;
    while (current != nullptr && current->key != data) {
        if (data < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == nullptr) {
        return nullptr;
    }

    if (current->key == data) {
        return current;
    }
    return nullptr;
}

BinarySearchTree::BSTNode *BinarySearchTree::findSuccessor(BinarySearchTree::BSTNode *node) {
    if (node == nullptr) {
        return node;
    }

    // Jezeli wezel posiada prawego potomka to nastepnikiem jest wezel minimalny w prawym poddrzewie
    if (node->right != nullptr) {
        return searchMin(node->right);
    }

    // Jezeli wezel nie posiada prawego potomka, nastepnikiem jest pierwszy rodzic, dla ktorego wezel lezy w lewym poddrzewie
    BSTNode *upper;
    upper = node->parent;

    // Dopoki node jest prawym potomkiem wykonuj petle, jesli nim nie jest oznacza to ze doszlismy do szczytu lewego poddrzewa
    while (upper != nullptr && node == upper->right) {
        node = upper;
        upper = upper->parent;
    }

    return upper;
}

BinarySearchTree::BSTNode *BinarySearchTree::searchMin(BinarySearchTree::BSTNode *node) {
    if (node == nullptr) {
        return nullptr;
    }
    BSTNode *minNode = node;
    while (minNode->left != nullptr) {
        minNode = minNode->left;
    }
    return minNode;
}

BinarySearchTree::BSTNode *BinarySearchTree::searchMax(BinarySearchTree::BSTNode *node) {
    if (node == nullptr) {
        return nullptr;
    }
    BSTNode *maxNode = node;
    while (maxNode->right != nullptr) {
        maxNode = maxNode->right;
    }
    return maxNode;
}

void BinarySearchTree::removeTreeDownFromNode(BSTNode *current) {
    BSTNode *temp = current;

    BSTNode *left = current->left;
    if (left != nullptr) {
        removeTreeDownFromNode(left);
    }
    BSTNode *right = current->right;
    if (right != nullptr) {
        removeTreeDownFromNode(right);
    }

    delete temp;
    size--;
}

void BinarySearchTree::removeAll() {
    if (root == nullptr) {
        return;
    }
    removeTreeDownFromNode(root);
    root = nullptr;
}
