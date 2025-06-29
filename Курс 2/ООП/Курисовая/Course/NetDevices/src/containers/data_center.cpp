#include <iostream>
#include "data_center.h"
#include "../devices/net_device.h"

/**
* Коструктор по умолчанию
*/
DataCenter::DataCenter() : Container() {
	
}

/**
* Оператор получения элемента по индексу
*
* @param индекс элемента
* @return указатель на элемент
*/
ServerRoom<Repeater>* DataCenter::operator[](int index) {
	return static_cast<ServerRoom<Repeater>*>(Container::operator[](index));
}

/**
* Метод, добавляющий элемент в контейнер
*
* @param указатель на добавляемое значение
*/
void DataCenter::add(void* device) {
	Container::add(device);
}

/**
* Метод, очищающий контейнер
*/
void DataCenter::clear() {
	Container::seek(Container::size());
}

/**
* Метод, возвращающий количество заданных элементов в контейнере
*
* @param указатель на искомое значение
* @return количество элементов
*/
int DataCenter::count(void* item) {
	return Container::count(item);
}

/**
* Метод, возвращающий общее количество устройств
*
* @return общее количество устройств
*/
int DataCenter::get_total_devices() {
	int count = 0;
	for (int i = 0; i < Container::size(); i++)
		count += static_cast<ServerRoom<Repeater>*>(Container::operator[](i))->size();
	return count;
}

/**
* Метод, возвращающий данные из контейнера в виде вектора
*
* @return данные из контейнера в виде вектора
*/
std::vector<void*> DataCenter::get_vector() {
	return Container::get_vector();
}

/**
* Метод, удаляющий заданое количество элементов с конца контейнера
*
* @param количество удаляемых элементов
*/
void DataCenter::seek(int count) {
	Container::seek(count);
}

/**
* Метод, возвращающий размер контейнера
*
* @return размер контейнера
*/
int DataCenter::size() {
	return Container::size();
}
