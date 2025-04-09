// Variant 5

#pragma once
#include "network.h"
#include <ostream>

class ServerRoom {

private:
    // Структура-"полка" (динамический список)
	struct Shelf {
        const Switch* device;
		Shelf* next;
    };
    // Указатели на первую и последнюю полку
    Shelf* first, * last;
    Shelf* get_shelf(ServerRoom*, int);

public:
    ServerRoom();
    ServerRoom(Switch&);
    ~ServerRoom();

    ServerRoom& operator+(Switch&);  // Оператор присваивания ServerRoom и Switch
    ServerRoom& operator--(int); // Оператор декремента
    const Switch* operator[](int); // Оператор взятия по индексу
    friend bool operator==(ServerRoom&, ServerRoom&); // Оператор сравнения
    friend std::ostream& operator<<(std::ostream& stream, ServerRoom&); // Оператор потокового вывода

    void print(int);
	void sort();
    int get_room_size();
    const Switch* search(int*);
    const Switch** get_array();
};
