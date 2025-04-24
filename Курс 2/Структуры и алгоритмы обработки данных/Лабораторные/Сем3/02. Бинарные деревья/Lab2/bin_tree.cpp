#include <iostream>
#include "bin_tree.h"

void BinTree::_create_node(Node*& node, int value) {
    if (node == NULL) {
        node = new Node;
        node->data = value;
        node->left = NULL;
        node->right = NULL;
    }
}

void BinTree::_print_node(Node*& node, int& variant) {
    if (node != NULL) {
        if (variant == 0) std::cout << node->data << " "; // Прямой 
        _print_node(node->left, variant);
        if (variant == 1) std::cout << node->data << " "; // Симметричный
        _print_node(node->right, variant);
        if (variant == 2) std::cout << node->data << " "; // Обратный
    }
}

void BinTree::_add(Node*& node, int& value) {
    if (node == NULL) _create_node(node, value);
    else {
        switch (rand() % 2) {
        case 0: {
            if (node->left) _add(node->left, value);
            else _create_node(node->left, value);
            break;
        }
        case 1: {
            if (node->right) _add(node->right, value);
            else _create_node(node->right, value);
            break;
        }
        }
    }
}

BinTree::BinTree(int size) {
    root = NULL;
    this->size = size;
}

void BinTree::add(int value) {
    _add(this->root, value);
}

void BinTree::generate() {
    for (int i = 0; i < this->size; i++) {
        int value = pow(-1, rand() % 2) * (rand() % 10);
        add(value);
    }
    std::cout << std::endl;
}

void BinTree::print(int var) {
    _print_node(this->root, var);
    std::cout << std::endl;
}