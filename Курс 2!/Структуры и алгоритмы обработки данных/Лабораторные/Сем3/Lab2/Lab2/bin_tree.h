#pragma once
#include <iostream>

class BinTree {
private:
    struct Node {
        int data;
        Node* left, * right;
    };

    void _create_node(Node*&, int);
    void _print_node(Node*&, int&);
    void _add(Node*&, int&);
    friend void copy_tree(BinTree*, BinTree*, Node*);

public:

    int size;
    Node* root;

    static const int P_DIRECT = 0;
    static const int P_PARITY = 1;
    static const int P_REVERSE = 2;

    BinTree(int);

    void add(int);
    void generate();
    void print(int);
};
