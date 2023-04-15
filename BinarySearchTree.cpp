//
// Created by lukas on 29.03.2023.
//

#include "BinarySearchTree.h"
#include "iostream"
#include "bits/stdc++.h"

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

BinarySearchTree::BNode *BinarySearchTree::getRoot() {
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
            printKeyUtil(root->left);
        } else std::cout << "*";
        std::cout << ",";
        if (root->right != nullptr) {
            printKeyUtil(root->right);
        } else std::cout << "*";
        std::cout << ")";
    }
}

void BinarySearchTree::printKeyUtil(BinarySearchTree::BNode *node) {
    std::cout << node->key << "(";
    if (node->left != nullptr) {
        printKeyUtil(node->left);
    } else std::cout << "*";
    std::cout << (",");
    if (node->right != nullptr) {
        printKeyUtil(node->right);
    } else std::cout << "*";
    std::cout << ")";
}

void BinarySearchTree::display2D() {
    display2DUtil(root, 0);
}

void BinarySearchTree::display2DUtil(BNode *node, int space) {
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
    BNode *newNode = new BNode;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->key = data;

    BNode *tmp = root;

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
    size--;
    BNode *foundToDelete = findByValue(data);
    if (foundToDelete == nullptr) {
        return NULL;
    }

    BNode *Y, *X;
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

BinarySearchTree::BNode *BinarySearchTree::findByValue(int data) {
    BNode *current = root;
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

BinarySearchTree::BNode *BinarySearchTree::findSuccessor(BinarySearchTree::BNode *node) {
    if (node == nullptr) {
        return node;
    }

    // Jezeli wezel posiada prawego potomka to nastepnikiem jest wezel minimalny w prawym poddrzewie
    if (node->right != nullptr) {
        return searchMin(node->right);
    }

    // Jezeli wezel nie posiada prawego potomka, nastepnikiem jest pierwszy rodzic, dla ktorego wezel lezy w lewym poddrzewie
    BNode *upper;
    upper = node->parent;

    // Dopoki node jest prawym potomkiem wykonuj petle, jesli nim nie jest oznacza to ze doszlismy do szczytu lewego poddrzewa
    while (upper != nullptr && node == upper->right) {
        node = upper;
        upper = upper->parent;
    }

    return upper;
}

BinarySearchTree::BNode *BinarySearchTree::searchMin(BinarySearchTree::BNode *node) {
    if (node == nullptr) {
        return nullptr;
    }
    BNode *minNode = node;
    while (minNode->left != nullptr) {
        minNode = minNode->left;
    }
    return minNode;
}

BinarySearchTree::BNode *BinarySearchTree::searchMax(BinarySearchTree::BNode *node) {
    if (node == nullptr) {
        return nullptr;
    }
    BNode *maxNode = node;
    while (maxNode->right != nullptr) {
        maxNode = maxNode->right;
    }
    return maxNode;
}

void BinarySearchTree::removeTreeDownFromNode(BNode *current) {
    BNode *temp = current;

    BNode *left = current->left;
    if (left != nullptr) {
        removeTreeDownFromNode(left);
    }
    BNode *right = current->right;
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

void BinarySearchTree::rotateRight(int data) {
    BNode *nodeA = findByValue(data);
    rotateRight(nodeA);
}

void BinarySearchTree::rotateLeft(int data) {
    BNode *nodeA = findByValue(data);
    rotateLeft(nodeA);
}

void BinarySearchTree::rotateRight(BinarySearchTree::BNode *node) {
    BNode *nodeA = node;
    if (nodeA == nullptr) {
        if (!automaticTests) {
            std::cout << "Node does not exist!" << std::endl;
        }
        return;
    }
    BNode *parentA = nodeA->parent;
    BNode *pivot = nodeA->left;

    if (pivot == nullptr) {
        if (!automaticTests) {
            std::cout << "Node does not have a left child!" << std::endl;
        }
        return;
    }
    nodeA->left = pivot->right;
    if (nodeA->left != nullptr) {
        nodeA->left->parent = nodeA;
    }
    pivot->right = nodeA;       // prawym synem pivota saje sie A
    pivot->parent = parentA;    // ojcem pivota staje sie ojciec A
    nodeA->parent = pivot;      // ojcem A staje sie pivot
    if (parentA == nullptr) {
        root = pivot;           // jesli A byl poprzednio korzeniem
        return;
    }
    if (parentA->left == nodeA) {   // w przeciwnym wypadku, nalezy uaktualnic ojca A
        parentA->left = pivot;
    } else {
        parentA->right = pivot;
    }
}

void BinarySearchTree::rotateLeft(BinarySearchTree::BNode *node) {
    BNode *nodeA = node;
    if (nodeA == nullptr) {
        if (!automaticTests) {
            std::cout << "Node does not exist!" << std::endl;
        }
        return;
    }
    BNode *parentA = nodeA->parent;
    BNode *pivot = nodeA->right;

    if (pivot == nullptr) {
        if (!automaticTests) {
            std::cout << "Node does not have a right child!" << std::endl;
        }
        return;
    }
    nodeA->right = pivot->left;
    if (nodeA->right != nullptr) {
        nodeA->right->parent = nodeA;
    }
    pivot->left = nodeA;
    pivot->parent = parentA;
    nodeA->parent = pivot;
    if (parentA == nullptr) {
        root = pivot;
        return;
    }
    if (parentA->left == nodeA) {
        parentA->left = pivot;
    } else {
        parentA->right = pivot;
    }
}

void BinarySearchTree::balanceTreeDSW() {
    // Pierwszy etap DSW
    createLinearTree();
    // Drugi etap DSW
    createBalancedTRee();
}

void BinarySearchTree::createLinearTree() {
    BNode *tmp = root;
    // prostowanie drzewa rotacjami w lewo
    while (tmp != nullptr) {
        if (tmp->left != nullptr) {
            rotateRight(tmp);
            tmp = tmp->parent;
        } else {
            tmp = tmp->right;
        }
    }
}

void BinarySearchTree::createBalancedTRee() {
    auto m = (unsigned) pow(2, floor(log2(size + 1))) - 1;
    BNode *tmp = root;
    // wykonanie n (liczba elementow) - m rotacji w lewo od korzenia co drugi wierzcholek
    for (int i = 0; i < size - m; i++) {
        rotateLeft(tmp);
        tmp = tmp->parent->right;
    }
    // w dalszej czesci wykonanie m rotacji w lewo, startujac od korzenia co drugi wierzcholek
    while (m > 1) {
        tmp = root;
        m = (unsigned) floor(m / 2);
        // wykonaj m rotacji w lewo startujac od korzenia co drugi wierzcholek
        for (int i = 0; i < m; i++) {
            rotateLeft(tmp);
            if (tmp != nullptr) {
                tmp = tmp->parent->right;
            }
        }
    }
}
