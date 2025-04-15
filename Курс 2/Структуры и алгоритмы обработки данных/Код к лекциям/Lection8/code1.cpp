#include <iostream>
#include <fstream>

struct Node{
    std::string data;
    int k;
    Node* left, * right;
};

void formTree(Node*& root, std::string key) {
    if (root == NULL) {
        root = new Node;
        root->data = key;
        root->k = 1;
        root->left = NULL;
        root->right = NULL;
    } else if (key < root->data)
        formTree(root->left, key);
    else if (key > root->data)
        formTree(root->left, key);
    else root->k++;
}

void printTree(Node*& root) {
    if (root != NULL) {
        printTree(root->left);
        std::cout << root->data << " - " << root->k << std::endl;
        printTree(root->right);
    }
}

int main() {
    const int n = 10;
    Node* root = NULL;
    std::ifstream f("input.txt");
    std::string word;
    while (!f.eof()) {
        f >> word;
        formTree(root, word);
    }        
    printTree(root);
    return 0;
}