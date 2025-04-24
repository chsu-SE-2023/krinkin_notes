#pragma once
#include <iostream>

template <class T>
class SearchTree {

public:
	struct Node {
		T data; int count;
		Node* left, * right;
		Node(T);
	};

private:
	Node* root = nullptr;
	void create(Node*&, T&);
	void search(Node*&, Node*&, T&);
	void to_datagrid(Node*&, System::Windows::Forms::DataGridView^&, int&);

public:
	void add(T);
	const Node* search(T);
	void to_datagrid(System::Windows::Forms::DataGridView^, int = 0);
};