#pragma once
#include <iostream>

class SearchTree {

private:

	struct Node {
		int data;
		Node* left, * right;
		Node(int data) {
			this->data = data;
			left = nullptr;
			right = nullptr;
		}
		~Node() {
			delete left;
			delete right;
		}
	};
	Node* root;
	void build(Node*& root, int key);
	void print(Node*& root);
public:
	void build(int key);
	void print();
};