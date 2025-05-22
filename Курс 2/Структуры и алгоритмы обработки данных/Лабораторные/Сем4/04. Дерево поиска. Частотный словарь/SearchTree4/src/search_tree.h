#pragma once
#include <iostream>
#include <vector>

template <class T>
class SearchTree {

public:
	struct Node {
		T data; int count;
		Node* left, * right;
		Node(T, int);
		~Node();
	};

private:
	Node* root = nullptr;
	void create(Node*&, T&, int&);
	void search(Node*&, Node*&, T&);
	void to_datagrid(Node*&, System::Data::DataTable^&);
	void to_vector(Node*&, std::vector<Node*>&);
	void copy(Node*&, SearchTree&, int&);

public:
	SearchTree();
	SearchTree(SearchTree&, int = -1);
	~SearchTree();
	void add(T, int = 1);
	const Node* search(T);
	void to_datagrid(System::Data::DataTable^);
	void to_vector(std::vector<Node*>&);
	static bool sorter(Node*, Node*);
};