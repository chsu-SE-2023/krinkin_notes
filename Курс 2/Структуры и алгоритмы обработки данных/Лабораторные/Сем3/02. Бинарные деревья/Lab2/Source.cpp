#include <iostream>
#include "bin_tree.h"

void copy_tree(BinTree* tree, BinTree* neg_tree, BinTree::Node* node) {
    if (node != NULL) {
        if (node->data < 0)
            neg_tree->add(node->data);
        copy_tree(tree, neg_tree, node->left);
        copy_tree(tree, neg_tree, node->right);
    }
}

int main() {
    srand(578);
    std::cout << "Tree 1:" << std::endl;
    int size = 5 + rand() % 15;
    BinTree tree = BinTree(size);
    tree.generate();

    std::cout << " - Direct pass: ";
    tree.print(BinTree::P_DIRECT);
    std::cout << " - Parity pass: " ;
    tree.print(BinTree::P_PARITY);
    std::cout << " - Reverse pass: " ;
    tree.print(BinTree::P_REVERSE);
    std::cout << std::endl;

    std::cout << "Tree 2:" << std::endl;
    BinTree neg_tree = BinTree(size);
    copy_tree(&tree, &neg_tree, tree.root);

    std::cout << " - Direct pass: ";
    neg_tree.print(BinTree::P_DIRECT);
    std::cout << " - Parity pass: ";
    neg_tree.print(BinTree::P_PARITY);
    std::cout << " - Reverse pass: ";
    neg_tree.print(BinTree::P_REVERSE);
    
    return 0;
}
