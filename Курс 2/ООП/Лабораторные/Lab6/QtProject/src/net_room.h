#pragma once
#include <ostream>

template <typename T>
class ServerRoom {

private:
    // Структура-"полка" (динамический список)
	struct Shelf {
        const T* device;
		Shelf* next;
    };
    // Указатели на первую и последнюю полку
    Shelf* first, * last;
    Shelf* get_shelf(ServerRoom<T>*, int);
    friend class Tests;

public:
    ServerRoom();
    ServerRoom(T&);
    ~ServerRoom();

    ServerRoom<T>& operator+(T&);  // Оператор присваивания ServerRoom и Switch
    ServerRoom<T>& operator--(int); // Оператор декремента
    const T* operator[](int); // Оператор взятия по индексу
    friend bool operator== (ServerRoom<T>&, ServerRoom<T>&); // Оператор сравнения
    friend std::ostream& operator<< (std::ostream& stream, ServerRoom<T>&); // Оператор потокового вывода

    void add(const T&);
    void seek(int);
    void print(int);
	void sort();
    const T* search(std::array<int, 5>&);
    int get_size();
    const T** get_array();
};
