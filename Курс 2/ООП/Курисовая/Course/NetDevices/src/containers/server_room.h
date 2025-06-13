#pragma once
#include "../misc/address.h"
#include "../devices/router.h"
#include "server_room.h"

template <typename T>
class ServerRoom {

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
    Node* get_node(ServerRoom<T>*, int);

public:
    ServerRoom();
    ServerRoom(T&);
    ServerRoom(const ServerRoom&);
    ~ServerRoom();
    ServerRoom<T>& operator--(int);
    T* operator[](int);
    friend bool operator== (const ServerRoom<T>&, const ServerRoom<T>&);
    friend bool operator!= (const ServerRoom<T>&, const ServerRoom<T>&);
    void add(T&);
    std::vector<T*> get_vector();
    void seek(int);
	void sort();
    T* search(MAC_Address);
    int size();
};
