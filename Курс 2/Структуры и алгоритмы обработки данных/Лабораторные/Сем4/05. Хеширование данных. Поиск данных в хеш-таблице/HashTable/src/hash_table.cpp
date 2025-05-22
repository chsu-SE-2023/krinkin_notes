#include <cmath>
#include "hash_table.h"

int MyHashTable::cls_count = 0;
int MyHashTable::a = 0;
int MyHashTable::c = 0;

/**
* Конструктор хеш-таблицы
* 
* @param количество классов
*/
MyHashTable::MyHashTable(int class_count) {
	this->cls_count = class_count;
	for (int i = 0; i < cls_count; i++)
		table.push_back({});
}

/**
* Метод, добавляющий значение в хеш-таблицу
*
* @param значение
* @param хеш-функция
*/
void MyHashTable::add(float key, int (*hash_f)(float)) {
	table[hash_f(key)].push_back(key);
}

/**
* Метод, возвращающий общее количество коллизий
*
* @param количество коллизий
*/
int MyHashTable::getColCount() {
	int count = 0;
	for (int i = 0; i < table.size(); i++)
		if (table[i].size() > 1) count += table[i].size() - 1;
	return count;
}

/**
* Метод, возвращающий процент заполняемости
*
* @param процент заполняемости
*/
int MyHashTable::getFillPercent() {
	int filled = 0;
	for (int i = 0; i < table.size(); i++)
		if (table[i].size() > 0) filled++;
	return ((float)filled / (float)table.size()) * 100.0F;
};

/**
* Метод, возвращающий номер самого большого класса
*
* @param номер самого большого класса
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
* Статическая хеш функция h(x) = x % B
*
* @param класс в хеш-таблице
*/
int MyHashTable::hashA(float key) {
	return (int)key % cls_count;
}

/**
* Статическая хеш функция h(x) = (ax + c) % B
*
* @param класс в хеш-таблице
*/
int MyHashTable::hashB(float key) {
	return (a * (int)key + c ) % cls_count;
}

/**
* Метод, округляющий действительное число до n знаков после запятой
*
* @param округляемое значение
*/
float MyHashTable::round(float value, int n) {
	int zeros = std::pow(10, F_PRESITION);
	return std::round(value * zeros) / zeros;
}

/**
* Метод, осуществляющий поиск в хеш-таблице
*
* @param искомое значение
* @param хеш-функция
* @return номер класса в хеш-таблице
*/
int MyHashTable::search(float key, int (*hash_f)(float)) {
	int cls = hash_f(key);
	for (int i = 0; i < table[cls].size(); i++)
		if (table[cls][i] == key) return cls;
	return -1;
}

/**
* Метод, устанавливающий значение a
*
* @param значение a
*/
void MyHashTable::setA(int value) {
	this->a = value;
}

/**
* Метод, устанавливающий значение c
*
* @param значение c
*/
void MyHashTable::setC(int value) {
	this->c = value;
}

/**
* Метод, вносящий данные из хеш-таблицы в CLR-таблицу
*
* @param ссылка на CLR-таблицу
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
