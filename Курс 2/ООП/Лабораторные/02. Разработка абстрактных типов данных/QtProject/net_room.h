// Variant 5

#pragma once
#include "network.h"

class ServerRoom {

private:
    // Структура-"полка" (динамический список)
	struct Shelf {
        const Switch* device;
		Shelf* next;
    };
    // Указатели на первую и последнюю полку
    Shelf* first, * last;
    Shelf* get_shelf(int);

public:
    ServerRoom();
    ServerRoom(const Switch*);
    ~ServerRoom();

    void add(const Switch*);
    void del();
    void print(int);
	void sort();
    int get_room_size();
    const Switch* search(int*);
    const Switch* get_device(int);
    const Switch** get_array();
};
