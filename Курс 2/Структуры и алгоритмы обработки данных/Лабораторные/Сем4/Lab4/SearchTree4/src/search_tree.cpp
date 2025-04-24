#include "search_tree.h"
#include <iostream>

// Инстанцирование для std::wstring
template class SearchTree<std::wstring>;
template SearchTree<std::wstring>::Node::Node(std::wstring data);
template void SearchTree<std::wstring>::create(Node*&, std::wstring&);
template void SearchTree<std::wstring>::search(Node*&, Node*&, std::wstring&);
template void SearchTree<std::wstring>::to_datagrid(Node*&, System::Windows::Forms::DataGridView^&, int&);
template void SearchTree<std::wstring>::add(std::wstring);
template const SearchTree<std::wstring>::Node* SearchTree<std::wstring>::search(std::wstring);
template void SearchTree<std::wstring>::to_datagrid(System::Windows::Forms::DataGridView^, int);

// Инстанцирование для std::string
template class SearchTree<std::string>;
template SearchTree<std::string>::Node::Node(std::string data);
template void SearchTree<std::string>::create(Node*&, std::string&);
template void SearchTree<std::string>::search(Node*&, Node*&, std::string&);
template void SearchTree<std::string>::to_datagrid(Node*&, System::Windows::Forms::DataGridView^&, int&);
template void SearchTree<std::string>::add(std::string);
template const SearchTree<std::string>::Node* SearchTree<std::string>::search(std::string);
template void SearchTree<std::string>::to_datagrid(System::Windows::Forms::DataGridView^, int);


template <class T>
SearchTree<T>::Node::Node(T data) {
	/*
	* Коструктор листа дерева
	*/
	this->data = data;
	this->count = 1;
	this->left = nullptr;
	this->right = nullptr;
}

template <class T>
void SearchTree<T>::create(Node*& root, T& key) {
	/*
	* Метод, создающий новый лист дерева
	*/
	if (root == nullptr)
		root = new Node(key);
	else if (key < root->data)
		create(root->left, key);
	else if (key > root->data)
		create(root->right, key);
};

template <class T>
void SearchTree<T>::search(Node*& root, Node*& result, T& key) {
	/*
	* Метод, производящий рекурсивный поиск по дереву
	*/
	if (root != nullptr) {
		if (key == root->data)
			result = root;
		else if (key < root->data)
			search(root->left, result, key);
		else if (key > root->data)
			search(root->right, result, key);
	}
}

template <class T>
void SearchTree<T>::to_datagrid(Node*& root, System::Windows::Forms::DataGridView^& table, int& len) {
	/*
	* Метод, рекурсивно заполняющий заданную таблицу значениями из дерева
	*/
	if (root != nullptr) {
		to_datagrid(root->left, table, len);
		if (len) {
			if (root->data.size() == len) {
				int count = table->RowCount++;
				table->Rows[count]->Cells[0]->Value = gcnew System::String(root->data.c_str());
				table->Rows[count]->Cells[1]->Value = root->count;
			}
		}
		else {
			int count = table->RowCount++;
			table->Rows[count]->Cells[0]->Value = gcnew System::String(root->data.c_str());
			table->Rows[count]->Cells[1]->Value = root->count;
		}
		to_datagrid(root->right, table, len);
	}
};

template <class T>
void SearchTree<T>::add(T key) {
	/*
	* Метод, добавляющий значение в дерево
	*/
	Node* value = nullptr;
	search(this->root, value, key);
	if (value == nullptr)
		create(this->root, key);
	else value->count++;
};

template <class T>
typename const SearchTree<T>::Node* SearchTree<T>::search(T key) {
	/*
	* Интерфейс для рекурсивного search()
	*/
	Node* result = nullptr;
	search(this->root, result, key);
	return result;
}

template <class T>
void SearchTree<T>::to_datagrid(System::Windows::Forms::DataGridView^ table, int len) {
	/*
	* Интерфейс для рекурсивного to_datagrid()
	*/
	to_datagrid(this->root, table, len);
}
