#include <map>
#include <iostream>
#include "huffman.h"

/*
* Рекурсивная функция, строящая дерево Хаффмана
*/
void HuffmanTree::makeTree(int& size) {
    if (size > 1) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int n1 = 0, n2 = 0;

        for (int i = 0; i < BYTE_MAX; i++)
            if (trees[i] != nullptr && trees[i]->p < min1) {
                n1 = i; min1 = trees[i]->p;
            }
        for (int i = 0; i < BYTE_MAX; i++)
            if (trees[i] != nullptr && trees[i]->p < min2 && i != n1) {
                n2 = i; min2 = trees[i]->p;
            }

        Node* tmp = new Node;
        tmp->left = trees[n1]; tmp->right = trees[n2];
        tmp->p = trees[n1]->p + trees[n2]->p;
        tmp->parent = nullptr;
        trees[n1]->parent = tmp; trees[n2]->parent = tmp;
        trees[n1] = tmp; trees[n2] = nullptr;
        makeTree(--size);
    }
}

/*
* Рекурсивная функция, строящая коды для символов на основе дерева Хаффмана
*/
void HuffmanTree::buildCodes(Node* node, const std::string& code) {
    if (!node) return;
    if (node->p == 0) return;

    // Если потомков нет - код найден
    if (!node->left && !node->right) {
        codes[node->c] = code; 
    }

    buildCodes(node->left, code + "0");
    buildCodes(node->right, code + "1");
}

HuffmanTree::HuffmanTree() {
    for (int i = 0; i < BYTE_MAX; i++) {
        trees[i] = new Node;
        trees[i]->c = i;
        freq[i] = 0;
    }
}

HuffmanTree::~HuffmanTree() {
    codes.clear();
    freq.fill(0);
    //delete root;
}

/*
* Метод для добавления байта в дерево некоторое кол-во раз
*/
void HuffmanTree::addByte(unsigned char byte, int count) {
    trees[byte]->p += count;
    freq[byte] += count;
}

/*
* Метод построения дерева Хаффмана, вызывающий рекурсивные
* функции по построению дерева и нахождения кодов для байтов
*/
void HuffmanTree::makeTree() {
    int size = BYTE_MAX;
    makeTree(size);
    for (int i = 0; i < BYTE_MAX; i++)
        if (trees[i] != nullptr) { root = trees[i]; break; };
    buildCodes(root, "");
}

/*
* Метод для получения кода байта
*/
std::string HuffmanTree::getCode(unsigned char byte) {
    return codes[byte];
}

/*
* Метод для получения частот
*/
std::array<int, BYTE_MAX> HuffmanTree::getFreq() const {
    return freq;
}

/*
* Метод для получения корня дерева
*/
HuffmanTree::Node* HuffmanTree::getRoot() {
    return root;
};

