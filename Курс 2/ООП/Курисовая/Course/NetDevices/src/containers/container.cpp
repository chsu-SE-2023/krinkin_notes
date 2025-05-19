#include <iostream>
#include "container.h"

/**
* ���������� ��� ���������
* 
* @param ��������� �� �������� ������
*/
Container::Node::Node(void* data) {
	this->data = data;
	this->next = nullptr;
}

/**
* ���������� ��� ���������. ��� �������� �������� ��������
* ����� ������� � ��������� �� ���, � ����� ����� � ����������
*/
Container::Node::~Node() {
	if (data) delete data;
	if (next) delete next;
}

/**
* ���������� �� ���������
*/
Container::Container() {
	this->first = new Node(nullptr);
	this->last = this->first;
}

/**
* ������������ - ������� ��� ���������-"�����"
*/
Container::~Container() {
	if (first) delete first;
	if (last) delete last;
}

/**
* ��������� ����� ��� ��������� �������� �� �������
* 
* @param ������ ��������
* @return ��������� �� �������
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
* �������� ��������� �������� �� �������
*
* @param ������ ��������
* @return ��������� �� �������
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
* �����, ����������� ������� � �����������
*
* @param ��������� �� ����������� ��������
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
* �����, ������������ ���������� �������� ��������� � ����������
*
* @param ��������� �� ������� ��������
* @return ���������� ���������
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
* �����, ��������� ������� ���������� ��������� � ����� ����������
*
* @param ���������� ��������� ���������
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
* �����, ������������ ������ ����������
*
* @return ������ ����������
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