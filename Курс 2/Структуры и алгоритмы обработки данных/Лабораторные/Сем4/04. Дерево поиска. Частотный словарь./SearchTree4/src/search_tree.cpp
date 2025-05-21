#include "search_tree.h"
#include <iostream>
#include <vector>

// ��������������� ��� std::wstring
template class SearchTree<std::wstring>;
template SearchTree<std::wstring>::Node::Node(std::wstring data);
template void SearchTree<std::wstring>::create(Node*&, std::wstring&);
template void SearchTree<std::wstring>::search(Node*&, Node*&, std::wstring&);
template void SearchTree<std::wstring>::to_datagrid(Node*&, System::Data::DataTable^&, int&);
template void SearchTree<std::wstring>::to_vector(Node*&, std::vector<Node*>&, int&);
template void SearchTree<std::wstring>::add(std::wstring);
template const SearchTree<std::wstring>::Node* SearchTree<std::wstring>::search(std::wstring);
template void SearchTree<std::wstring>::to_datagrid(System::Data::DataTable^, int);
template void SearchTree<std::wstring>::to_vector(std::vector<Node*>&, int);

// ��������������� ��� std::string
template class SearchTree<std::string>;
template SearchTree<std::string>::Node::Node(std::string data);
template void SearchTree<std::string>::create(Node*&, std::string&);
template void SearchTree<std::string>::search(Node*&, Node*&, std::string&);
template void SearchTree<std::string>::to_datagrid(Node*&, System::Data::DataTable^&, int&);
template void SearchTree<std::string>::add(std::string);
template const SearchTree<std::string>::Node* SearchTree<std::string>::search(std::string);
template void SearchTree<std::string>::to_datagrid(System::Data::DataTable^, int);

/**
* ���������� ����� ������
* 
* @param ����������� ������
*/
template <class T>
SearchTree<T>::Node::Node(T data) {
	this->data = data;
	this->count = 1;
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
* ������������ ������
*/
template <class T>
SearchTree<T>::~SearchTree() {
	delete root;
}

/**
* ��������� �����, ��������� ����� ���� ������
* 
* @param ��������� �� ������ ������
* @param ����������� � ����� ������
*/
template <class T>
void SearchTree<T>::create(Node*& root, T& key) {
	if (root == nullptr)
		root = new Node(key);
	else if (key < root->data)
		create(root->left, key);
	else if (key > root->data)
		create(root->right, key);
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
void SearchTree<T>::to_datagrid(Node*& root, System::Data::DataTable^& table, int& len) {
	if (root != nullptr) {
		to_datagrid(root->left, table, len);
		if (len) {
			// ���������� �������� ������ � �������� �������
			if (root->data.size() == len) {
				System::Data::DataRow^ row = table->NewRow();
				row[0] = gcnew System::String(root->data.c_str());
				row[1] = root->count;
				table->Rows->Add(row);
			}
		}
		else {
			System::Data::DataRow^ row = table->NewRow();
			row[0] = gcnew System::String(root->data.c_str());
			row[1] = root->count;
			table->Rows->Add(row);
		}
		to_datagrid(root->right, table, len);
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
void SearchTree<T>::to_vector(Node*& root, std::vector<Node*>& vec, int& len) {
	if (root != nullptr) {
		to_vector(root->left, vec, len);
		if (len) {
			// ���������� �������� ������ � �������� �������
			if (root->data.size() == len)
				vec.push_back(root);
		}
		else vec.push_back(root);
		to_vector(root->right, vec, len);
	}
};

/**
* �����, ����������� �������� � ������
* 
* @param ����������� ��������
*/
template <class T>
void SearchTree<T>::add(T key) {
	Node* value = nullptr;
	search(this->root, value, key); // ����� �������������
	if (value == nullptr) create(this->root, key);
	else value->count++;
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
void SearchTree<T>::to_datagrid(System::Data::DataTable^ table, int len) {
	to_datagrid(this->root, table, len);
}

/**
* �����, ����������� �������� ������ ���������� �� ������
* (��������� ��� ������������ to_vector())
* 
* @param ������ ���������� �� �����
* @param (��������������) ������ �����
*/
template <class T>
void SearchTree<T>::to_vector(std::vector<Node*>& vec, int len) {
	to_vector(this->root, vec, len);
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