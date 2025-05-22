#include <cmath>
#include "hash_table.h"

int MyHashTable::cls_count = 0;
int MyHashTable::a = 0;
int MyHashTable::c = 0;

/**
* ����������� ���-�������
* 
* @param ���������� �������
*/
MyHashTable::MyHashTable(int class_count) {
	this->cls_count = class_count;
	for (int i = 0; i < cls_count; i++)
		table.push_back({});
}

/**
* �����, ����������� �������� � ���-�������
*
* @param ��������
* @param ���-�������
*/
void MyHashTable::add(float key, int (*hash_f)(float)) {
	table[hash_f(key)].push_back(key);
}

/**
* �����, ������������ ����� ���������� ��������
*
* @param ���������� ��������
*/
int MyHashTable::getColCount() {
	int count = 0;
	for (int i = 0; i < table.size(); i++)
		if (table[i].size() > 1) count += table[i].size() - 1;
	return count;
}

/**
* �����, ������������ ������� �������������
*
* @param ������� �������������
*/
int MyHashTable::getFillPercent() {
	int filled = 0;
	for (int i = 0; i < table.size(); i++)
		if (table[i].size() > 0) filled++;
	return ((float)filled / (float)table.size()) * 100.0F;
};

/**
* �����, ������������ ����� ������ �������� ������
*
* @param ����� ������ �������� ������
*/
int MyHashTable::getLongestClass() {
	int max = 0;
	int max_i = 0;
	for (int i = 0; i < table.size(); i++)
		if (table[i].size() > max) { 
			max = table[i].size(); 
			max_i = i; 
		};
	return max_i;
};

/**
* ����������� ��� ������� h(x) = x % B
*
* @param ����� � ���-�������
*/
int MyHashTable::hashA(float key) {
	return (int)key % cls_count;
}

/**
* ����������� ��� ������� h(x) = (ax + c) % B
*
* @param ����� � ���-�������
*/
int MyHashTable::hashB(float key) {
	return (a * (int)key + c ) % cls_count;
}

/**
* �����, ����������� �������������� ����� �� n ������ ����� �������
*
* @param ����������� ��������
*/
float MyHashTable::round(float value, int n) {
	int zeros = std::pow(10, F_PRESITION);
	return std::round(value * zeros) / zeros;
}

/**
* �����, �������������� ����� � ���-�������
*
* @param ������� ��������
* @param ���-�������
* @return ����� ������ � ���-�������
*/
int MyHashTable::search(float key, int (*hash_f)(float)) {
	int cls = hash_f(key);
	for (int i = 0; i < table[cls].size(); i++)
		if (table[cls][i] == key) return cls;
	return -1;
}

/**
* �����, ��������������� �������� a
*
* @param �������� a
*/
void MyHashTable::setA(int value) {
	this->a = value;
}

/**
* �����, ��������������� �������� c
*
* @param �������� c
*/
void MyHashTable::setC(int value) {
	this->c = value;
}

/**
* �����, �������� ������ �� ���-������� � CLR-�������
*
* @param ������ �� CLR-�������
*/
void MyHashTable::toTable(System::Data::DataTable^& table) {
	for (int i = 0; i < this->table.size(); i++) {
		System::Data::DataRow^ row = table->NewRow();
		row[0] = i;
		for (int j = 0; j < this->table[i].size(); j++) {
			row[1] += this->table[i][j].ToString("F"+F_PRESITION) + "  ";
		}
		table->Rows->Add(row);
	}
}
