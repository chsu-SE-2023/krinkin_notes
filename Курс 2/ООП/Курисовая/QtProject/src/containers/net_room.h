#pragma once
#include <ostream>

template <typename T>
class ServerRoom {

private:
    // Структура-"полка" (двусвязный список)
	struct Shelf {
        T* device;
		Shelf* next;
        Shelf* prev;
        Shelf(T*);
        ~Shelf();
    };
    // Указатели на первую и последнюю полку
    Shelf* first, * last;
    Shelf* get_shelf(ServerRoom<T>*, int);

public:
    ServerRoom();
    ServerRoom(const T&);
    ~ServerRoom();
    ServerRoom<T>& operator--(int);
    T* operator[](int);
    friend bool operator== (ServerRoom<T>&, ServerRoom<T>&);
    friend bool operator!= (ServerRoom<T>&, ServerRoom<T>&);
    void add(const T&);
    void seek(int);
	void sort();
    T* search(std::array<int, 5>&);
    int size();
};
