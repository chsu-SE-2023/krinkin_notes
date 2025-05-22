#include "search_tree.h"
#include <iostream>
#include <vector>

// ��������������� ��� std::wstring
template class SearchTree<std::wstring>;
template SearchTree<std::wstring>::Node::Node(std::wstring data, int);
template void SearchTree<std::wstring>::create(Node*&, std::wstring&, int&);
template void SearchTree<std::wstring>::search(Node*&, Node*&, std::wstring&);
template void SearchTree<std::wstring>::to_datagrid(Node*&, System::Data::DataTable^&);
template void SearchTree<std::wstring>::to_vector(Node*&, std::vector<Node*>&);
template void SearchTree<std::wstring>::add(std::wstring, int);
template const SearchTree<std::wstring>::Node* SearchTree<std::wstring>::search(std::wstring);
template void SearchTree<std::wstring>::to_datagrid(System::Data::DataTable^);
template void SearchTree<std::wstring>::to_vector(std::vector<Node*>&);

// ��������������� ��� std::string
template class SearchTree<std::string>;
template SearchTree<std::string>::Node::Node(std::string data, int);
template void SearchTree<std::string>::create(Node*&, std::string&, int&);
template void SearchTree<std::string>::search(Node*&, Node*&, std::string&);
template void SearchTree<std::string>::to_datagrid(Node*&, System::Data::DataTable^&);
template void SearchTree<std::string>::to_vector(Node*&, std::vector<Node*>&);
template void SearchTree<std::string>::add(std::string, int);
template const SearchTree<std::string>::Node* SearchTree<std::string>::search(std::string);
template void SearchTree<std::string>::to_datagrid(System::Data::DataTable^);
template void SearchTree<std::string>::to_vector(std::vector<Node*>&);

/**
* ���������� ����� ������
* 
* @param ����������� ������
*/
template <class T>
SearchTree<T>::Node::Node(T data, int count) {
	this->data = data;
	this->count = count;
	this->left = nullptr;
	this->right = nullptr;
}

/**
* ������������ ����� ������
*/
template <class T>
SearchTree<T>::Node::~Node() {
	if (right) delete right;
	if (left) delete left;
}

/**
* ����������� ������ �� ���������
*/
template <class T>
SearchTree<T>::SearchTree() {
	root = nullptr;
}

/**
* ���������� ����������� ������
* 
* @param ������
* @param ������������ ����� �����
*/
template <class T>
SearchTree<T>::SearchTree(SearchTree& copy, int len) {
	// ��� ����������� �����������, ��� ��� ����� ������� ���� 
	// �� ������� ���-�� �������� ���� ������� �������
	this->copy(copy.root, *this, len); 
}

/**
* ������������ ������
*/
template <class T>
SearchTree<T>::~SearchTree() {
	delete root;
}

/**
* ��������� �����, ���������� ���������� �������� ������ ������ � ������
*
* @param ��������� �� ������ ������������ ������
* @param ������� ������
* @param ����������� �� ����� ��������
*/
template <class T>
void SearchTree<T>::copy(Node*& root, SearchTree& dest, int& len) {
	if (root != nullptr) {
		copy(root->left, dest, len);
		if (len != -1) {
			if (root->data.size() == len) dest.add(root->data, root->count);
		} else dest.add(root->data, root->count);
		copy(root->right, dest, len);
	}
}

/**
* ��������� �����, ��������� ����� ���� ������
* 
* @param ��������� �� ������ ������
* @param ����������� � ����� ������
*/
template <class T>
void SearchTree<T>::create(Node*& root, T& key, int& count) {
	if (root == nullptr)
		root = new Node(key, count);
	else if (key < root->data)
		create(root->left, key, count);
	else if (key > root->data)
		create(root->right, key, count);
};

/**
* ��������� �����, ������������ ����������� ����� �� ������
* 
* @param ��������� �� ������ ������
* @param ��������� ���� ������� ��������� ��������
* @param ������� ������
*/
template <class T>
void SearchTree<T>::search(Node*& root, Node*& result, T& key) {
	if (root != nullptr) {
		if (key == root->data)
			result = root;
		else if (key < root->data)
			search(root->left, result, key);
		else if (key > root->data)
			search(root->right, result, key);
	}
}

/**
* �����, ���������� ����������� �������� ������� ���������� �� ������
* 
* @param ��������� �� ������ ������
* @param CLR ������� (System::Data::DataTable)
* @param (��������������) ������ �����
*/
template <class T>
void SearchTree<T>::to_datagrid(Node*& root, System::Data::DataTable^& table) {
	if (root != nullptr) {
		to_datagrid(root->left, table);
		System::Data::DataRow^ row = table->NewRow();
		row[0] = gcnew System::String(root->data.c_str());
		row[1] = root->count;
		table->Rows->Add(row);
		to_datagrid(root->right, table);
	}
};

/**
* �����, ���������� ����������� �������� ������ ���������� �� ������
* 
* @param ��������� �� ������ ������
* @param ������ ���������� �� �����
* @param (��������������) ������ �����
*/
template <class T>
void SearchTree<T>::to_vector(Node*& root, std::vector<Node*>& vec) {
	if (root != nullptr) {
		to_vector(root->left, vec);
		vec.push_back(root);
		to_vector(root->right, vec);
	}
};

/**
* �����, ����������� �������� � ������
* 
* @param ����������� ��������
*/
template <class T>
void SearchTree<T>::add(T key, int count) {
	Node* value = nullptr;
	search(this->root, value, key); // ����� �������������
	if (value == nullptr) create(this->root, key, count);
	else value->count += count;
};

/**
* ����� ������ �� ������ (��������� ��� ������������ search())
* 
* @param ������� ��������
*/
template <class T>
typename const SearchTree<T>::Node* SearchTree<T>::search(T key) {
	Node* result = nullptr;
	search(this->root, result, key);
	return result;
}

/*
* �����, ����������� �������� ������� ���������� �� ������ 
* (��������� ��� ������������ to_datagrid())
* 
* @param CLR ������� (System::Data::DataTable)
* @param (��������������) ������ �����
*/
template <class T>
void SearchTree<T>::to_datagrid(System::Data::DataTable^ table) {
	to_datagrid(this->root, table);
}

/**
* �����, ����������� �������� ������ ���������� �� ������
* (��������� ��� ������������ to_vector())
* 
* @param ������ ���������� �� �����
* @param (��������������) ������ �����
*/
template <class T>
void SearchTree<T>::to_vector(std::vector<Node*>& vec) {
	to_vector(this->root, vec);
}

/**
* ����� �������� ������ ��� ���������� ������ ������.
* ���������� ��� ����� ���� �� ����������, ���� �� ��������, ���� 
* ���������� ���������.
* 
* @param ��������� �� ������ ���� 
* @param ��������� �� ������ ����
* @return ������ �������� (������ �� ������ �������) 
*/
template <class T>
bool SearchTree<T>::sorter(SearchTree<T>::Node* a, SearchTree<T>::Node* b) {
	if (a->count != b->count) {
		return a->count > b->count;
	}
	return a->data > b->data;
}