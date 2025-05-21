#include "search_tree.h"
#include <iostream>
#include <vector>

// Инстанцирование для std::wstring
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

// Инстанцирование для std::string
template class SearchTree<std::string>;
template SearchTree<std::string>::Node::Node(std::string data);
template void SearchTree<std::string>::create(Node*&, std::string&);
template void SearchTree<std::string>::search(Node*&, Node*&, std::string&);
template void SearchTree<std::string>::to_datagrid(Node*&, System::Data::DataTable^&, int&);
template void SearchTree<std::string>::add(std::string);
template const SearchTree<std::string>::Node* SearchTree<std::string>::search(std::string);
template void SearchTree<std::string>::to_datagrid(System::Data::DataTable^, int);

/**
* Коструктор листа дерева
* 
* @param сохраняемые данные
*/
template <class T>
SearchTree<T>::Node::Node(T data) {
	this->data = data;
	this->count = 1;
	this->left = nullptr;
	this->right = nullptr;
}

/**
* Декоструктор листа дерева
*/
template <class T>
SearchTree<T>::Node::~Node() {
	if (right) delete right;
	if (left) delete left;
}

/**
* Декоструктор дерева
*/
template <class T>
SearchTree<T>::~SearchTree() {
	delete root;
}

/**
* Приватный метод, создающий новый лист дерева
* 
* @param указатель на корень дерева
* @param сохраняемые в листе данные
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
* Приватный метод, производящий рекурсивный поиск по дереву
* 
* @param указатель на корень дерева
* @param указатель куда вернуть найденное значение
* @param искомые данные
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
* Метод, рекурсивно заполняющий заданную таблицу значениями из дерева
* 
* @param указатель на корень дерева
* @param CLR таблица (System::Data::DataTable)
* @param (необязательный) фильтр длины
*/
template <class T>
void SearchTree<T>::to_datagrid(Node*& root, System::Data::DataTable^& table, int& len) {
	if (root != nullptr) {
		to_datagrid(root->left, table, len);
		if (len) {
			// Добавление значений только с заданной длинной
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
* Метод, рекурсивно заполняющий заданный вектор значениями из дерева
* 
* @param указатель на корень дерева
* @param вектор указателей на листы
* @param (необязательный) фильтр длины
*/
template <class T>
void SearchTree<T>::to_vector(Node*& root, std::vector<Node*>& vec, int& len) {
	if (root != nullptr) {
		to_vector(root->left, vec, len);
		if (len) {
			// Добавление значений только с заданной длинной
			if (root->data.size() == len)
				vec.push_back(root);
		}
		else vec.push_back(root);
		to_vector(root->right, vec, len);
	}
};

/**
* Метод, добавляющий значение в дерево
* 
* @param добавляемое значение
*/
template <class T>
void SearchTree<T>::add(T key) {
	Node* value = nullptr;
	search(this->root, value, key); // Поиск существующего
	if (value == nullptr) create(this->root, key);
	else value->count++;
};

/**
* Метод поиска по дереву (интерфейс для рекурсивного search())
* 
* @param искомое значение
*/
template <class T>
typename const SearchTree<T>::Node* SearchTree<T>::search(T key) {
	Node* result = nullptr;
	search(this->root, result, key);
	return result;
}

/*
* Метод, заполняющий заданную таблицу значениями из дерева 
* (интерфейс для рекурсивного to_datagrid())
* 
* @param CLR таблица (System::Data::DataTable)
* @param (необязательный) фильтр длины
*/
template <class T>
void SearchTree<T>::to_datagrid(System::Data::DataTable^ table, int len) {
	to_datagrid(this->root, table, len);
}

/**
* Метод, заполняющий заданный вектор значениями из дерева
* (интерфейс для рекурсивного to_vector())
* 
* @param вектор указателей на листы
* @param (необязательный) фильтр длины
*/
template <class T>
void SearchTree<T>::to_vector(std::vector<Node*>& vec, int len) {
	to_vector(this->root, vec, len);
}

/**
* Метод задающий фильтр для сортировки листов дерева.
* Сравнивает два листа либо по количеству, либо по значению, если 
* количество одинаково.
* 
* @param указатель на первый лист 
* @param указатель на второй лист
* @return булево значение (больше ли первый второго) 
*/
template <class T>
bool SearchTree<T>::sorter(SearchTree<T>::Node* a, SearchTree<T>::Node* b) {
	if (a->count != b->count) {
		return a->count > b->count;
	}
	return a->data > b->data;
}