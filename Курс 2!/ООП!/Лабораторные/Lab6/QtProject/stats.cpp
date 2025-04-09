#include "stats.h"
#include "router.h"
#include "net_room.h"
#include <iostream>
#include <map>

Stats::Stats() {
	clients_total = 0;
};

Stats::~Stats() {
	this->clear();
};

void Stats::to_template(ServerRoom<Router>* r_room) const {
	/*
	 * Функция вносящая указатели на объекты из словаря
	 * в контейнерный класс
	 */
	for (const auto& pair: routers)
		for (int i = 0; i < pair.second; i++)
			r_room->add(*(pair.first));
};

void Stats::to_map(ServerRoom<Router>* r_room) {
	/*
	 * Функция вносящая указатели на объекты из
	 * контейнерного класса в словарь
	 */
	int count = 1, index = 0;
	std::cout << "obj index: "; std::cin >> index;
	std::cout << "count: "; std::cin >> count;

	const Router* obj = (*r_room)[index];
	clients_total += obj->clients_count() * count; // Учёт количества клиентов
	routers[obj] += count;
};

void Stats::to_map(Router* obj, int count = 1) {
	/*
	 * Функция вносящая указатель на некоторый
	 * объект Router указанное количество раз
	 * (по умолчанию = 1)
	 */
	clients_total += obj->clients_count() * count; // Учёт количества клиентов
	routers[obj] = count;
};

void Stats::increase(Router* obj, int value = 1) {
	/*
	 * Функция увеличивающая количество копий определённого
	 * объекта Router указанное количество раз
	 * (по умолчанию = 1)
	 */
	clients_total += obj->clients_count() * value; // Учёт количества клиентов
	routers[obj] += value;
};

void Stats::decrease(Router*obj, int value) {
	/*
	 * Функция уменьшающая количество копий определённого
	 * объекта Router указанное количество раз
	 * (по умолчанию = 1)
	 */
	clients_total -= obj->clients_count() * value; // Учёт количества клиентов
	routers[obj] -= value;
};

void Stats::remove(Router* obj) {
	/*
	 * Функция удаляющая указанный объект Router из словаря
	 */
	clients_total -= obj->clients_count() * routers[obj]; // Учёт количества клиентов
	routers.erase(obj);
};

void Stats::print() const {
	/*
	 * Функция выводящая статистику на экран по списку объектов Router
	 */	
	for (const auto& pair : routers) {
		std::cout << "Router address: " << pair.first->get_address() << ", count: " << pair.second << std::endl;
	}
};

int Stats::get_total() const {
	/*
	 * Функция возвращающая общее количество клиентов в сети
	 */
	return clients_total;
};

int Stats::get_total_devices() const {
	/*
	 * Функция возвращающая общее количество устройств (Router) в map
	 * с учётом копий
	 */
	int count = 0;
	for (const auto& pair : routers)
		count += pair.second;
	return count;
}

void Stats::clear() {
	/*
	 * Функция очищающая словарь объектов
	 */
	clients_total = 0;
	routers.clear();
};
