#pragma once
#include "../misc/address.h"
#include "server_room.h"

template <typename T>
class DataCenter {

private:
	struct Node {
        T* device;
        Node* next;
        Node* prev;
        Node(T*);
        ~Node();
    };
    // Указатели на первую и последнюю полку
    Node* first, * last;
    Node* get_node(DataCenter<T>*, int);

public:
    DataCenter();
    DataCenter(T&);
    ~DataCenter();
    DataCenter<T>& operator--(int);
    T* operator[](int);
    friend bool operator== (const DataCenter<T>&, const DataCenter<T>&);
    friend bool operator!= (const DataCenter<T>&, const DataCenter<T>&);
    void add(T&);
    void seek(int);
	void sort();
    T* search(MAC_Address);
    int size();
};
