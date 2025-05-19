#pragma once

class Container {

private:
	struct Node {
		void* data;
		Node* next;
		Node(void*);
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
	void seek(int);
	int size();
};