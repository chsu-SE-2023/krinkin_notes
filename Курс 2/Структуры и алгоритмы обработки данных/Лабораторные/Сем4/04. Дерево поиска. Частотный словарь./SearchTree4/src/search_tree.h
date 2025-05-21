#pragma once
#include <iostream>
#include <vector>

template <class T>
class SearchTree {

public:
	struct Node {
		T data; int count;
		Node* left, * right;
		Node(T);
		~Node();
	};

private:
	Node* root = nullptr;
	void create(Node*&, T&);
	void search(Node*&, Node*&, T&);
	void to_datagrid(Node*&, System::Data::DataTable^&, int&);
	void to_vector(Node*&, std::vector<Node*>&, int&);

public:
	~SearchTree();
	void add(T);
	const Node* search(T);
	void to_datagrid(System::Data::DataTable^, int = 0);
	void to_vector(std::vector<Node*>&, int = 0);
	static bool sorter(Node*, Node*);
};