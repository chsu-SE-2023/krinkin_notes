#include <iostream>
#include "container.h"

/**
* Коструктор для структуры
* 
* @param указатель на хранимые данные
*/
Container::Node::Node(void* data) {
	this->data = data;
	this->next = nullptr;
}

/**
* Деструктор для структуры. При удалении текущего элемента
* также удаляет и следующий за ним, а также связь с предыдущим
*/
Container::Node::~Node() {
	if (data) delete data;
	if (next) delete next;
}

/**
* Коструктор по умолчанию
*/
Container::Container() {
	this->first = new Node(nullptr);
	this->last = this->first;
}

/**
* Декоструктор - удаляет все структуры-"полки"
*/
Container::~Container() {
	if (first) delete first;
	if (last) delete last;
}

/**
* Приватный метод для получения элемента по индексу
* 
* @param индекс элемента
* @return указатель на элемент
*/
Container::Node* Container::get_node(int index) {
	Node* node = this->first;
	for (int i = 0; i < index; i++) {
		if (node != nullptr)
			node = node->next;
		else
			throw std::range_error("Index of element was out of range: " + index + '/' + i);
	}
	return node;
}

/**
* Оператор получения элемента по индексу
*
* @param индекс элемента
* @return указатель на элемент
*/
const void* Container::operator[](int index) {
	try {
		return get_node(index)->data;
	}
	catch (std::range_error err) {
		throw std::range_error(err.what());
	}
}

/**
* Метод, добавляющий элемент в конструктор
*
* @param указатель на добавляемое значение
*/
void Container::add(void* item) {
	if (this->last->data == nullptr) {
		this->last->data = item;
	}
	else {
		this->last->next = new Node(item);
		this->last = this->last->next;
		this->last->next = nullptr;
	}
}

/**
* Метод, возвращающий количество заданных элементов в контейнере
*
* @param указатель на искомое значение
* @return количество элементов
*/
int Container::count(void* item) {
	Node* current = first;
	int count = 0;
	while (current->next != nullptr) {
		if (current->data == item) count++;
		current = current->next;
	}
	return count;
}

/**
* Метод, удаляющий заданое количество элементов с конца контейнера
*
* @param количество удаляемых элементов
*/
void Container::seek(int count) {
	if (this->first == this->last) {
		this->first = nullptr;
		this->last = nullptr;
	}
	else {
		do {
			Node* prev = get_node(size() - 1);
			if (prev->next) delete prev->next;
			prev->next = nullptr;
			this->last = prev;
			count--;
		} while (count > 0);
	}
}

/**
* Метод, возвращающий размер контейнера
*
* @return размер контейнера
*/
int Container::size() {
	Node* current = first;
	int count = 0;
	while (current->next != nullptr) {
		count++;
		current = current->next;
	}
	return count;
}