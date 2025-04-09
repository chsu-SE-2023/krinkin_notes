#include <iostream>

struct Node {
    int data;
    Node *left, *right;
};

void add(Node*& node, int value) {
    if (node == NULL) {
        node = new Node;
        node->data = value;
        node->left = NULL;
        node->right = NULL;
    }
}

void print(Node* node) { // Прямой обход
    if (node != NULL) {
        std::cout << node->data << " ";
        print(node->left);
        print(node->right);
    }
}

void print_sim(Node* node) { // Симметричный обход
    if (node != NULL) {
        print(node->left);
        std::cout << node->data << " ";
        print(node->right);
    }
}

void print_rev(Node* node) { // Обратный обход
    if (node != NULL) {
        print(node->left);
        print(node->right);
        std::cout << node->data << " ";
    }
}

int main() {
    Node* root = NULL;
    add(root, 5);
    add(root->left, 6);
    add(root->right, 2);
    add(root->right->left, 3);
    add(root->right->right, 4);
    add(root->right->right->left, 7);
    print(root);
    return 0;
}