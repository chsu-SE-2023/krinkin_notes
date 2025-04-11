#include "search_tree.h"
#include <iostream>


void SearchTree::build(Node*& root, int key) {
	if (root == nullptr)
		root = new Node(key);
	else if (key < root->data)
		build(root->left, key);
	else if (key > root->data)
		build(root->right, key);
}

void SearchTree::print(Node*& root) {
	if (root != nullptr) {
		print(root->left);
		std::cout << root->data << " ";
		print(root->right);
	}
}

void SearchTree::build(int key) {
	build(this->root, key);
}

void SearchTree::print() {
	print(this->root);
}