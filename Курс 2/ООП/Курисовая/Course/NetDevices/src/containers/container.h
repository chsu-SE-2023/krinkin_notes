#pragma once
#include <vector>

class Container {

private:
	struct Node {
		void* data;
		Node* next;
		Node();
		Node(void*&);
		~Node();
	};
	Node* first, *last;
	Node* get_node(int);

public:
	Container();
	~Container();
	const void* operator[](int);
	void add(void*);
	int count(void*);
	std::vector<void*> get_vector();
	void seek(int);
	int size();
};