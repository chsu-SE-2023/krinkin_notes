#include "server_room.h"
#include "../devices/router.h"
#include "../misc/address.h"
#include <iostream>

#pragma region Instancing for Repeater
template class ServerRoom<Repeater>;
template ServerRoom<Repeater>::Node::Node(Repeater*);
template ServerRoom<Repeater>::Node::~Node();
template ServerRoom<Repeater>::Node* ServerRoom<Repeater>::get_node(ServerRoom<Repeater>*, int);
template ServerRoom<Repeater>::ServerRoom();
template ServerRoom<Repeater>::ServerRoom(Repeater&);
template ServerRoom<Repeater>::~ServerRoom();
template ServerRoom<Repeater>& ServerRoom<Repeater>::operator--(int);
template Repeater* ServerRoom<Repeater>::operator[](int);
template bool operator== (const ServerRoom<Repeater>&, const ServerRoom<Repeater>&);
template bool operator!= (const ServerRoom<Repeater>&, const ServerRoom<Repeater>&);
template void ServerRoom<Repeater>::add(Repeater&);
template std::vector<Repeater*> ServerRoom<Repeater>::get_vector();
template void ServerRoom<Repeater>::seek(int);
template void ServerRoom<Repeater>::sort();
template std::vector<Repeater*> ServerRoom<Repeater>::search(MAC_Address);
template std::vector <Repeater*> ServerRoom<Repeater>::search(int, int);
template int ServerRoom<Repeater>::size();
template int ServerRoom<Repeater>::cli_total();
#pragma endregion

#pragma region Instancing for WLRepeater
template class ServerRoom<WLRepeater>;
template ServerRoom<WLRepeater>::Node::Node(WLRepeater*);
template ServerRoom<WLRepeater>::Node::~Node();
template ServerRoom<WLRepeater>::Node* ServerRoom<WLRepeater>::get_node(ServerRoom<WLRepeater>*, int);
template ServerRoom<WLRepeater>::ServerRoom();
template ServerRoom<WLRepeater>::ServerRoom(WLRepeater&);
template ServerRoom<WLRepeater>::~ServerRoom();
template ServerRoom<WLRepeater>& ServerRoom<WLRepeater>::operator--(int);
template WLRepeater* ServerRoom<WLRepeater>::operator[](int);
template bool operator== (const ServerRoom<WLRepeater>&, const ServerRoom<WLRepeater>&);
template bool operator!= (const ServerRoom<WLRepeater>&, const ServerRoom<WLRepeater>&);
template void ServerRoom<WLRepeater>::add(WLRepeater&);
template std::vector<WLRepeater*> ServerRoom<WLRepeater>::get_vector();
template void ServerRoom<WLRepeater>::seek(int);
template void ServerRoom<WLRepeater>::sort();
template std::vector <WLRepeater*> ServerRoom<WLRepeater>::search(MAC_Address);
template std::vector <WLRepeater*> ServerRoom<WLRepeater>::search(int, int);
template std::vector <WLRepeater*> ServerRoom<WLRepeater>::search(std::string, SearchMode);
template int ServerRoom<WLRepeater>::size();
template int ServerRoom<WLRepeater>::cli_total();
#pragma endregion

#pragma region Instancing for Switch
template class ServerRoom<Switch>;
template ServerRoom<Switch>::Node::Node(Switch*);
template ServerRoom<Switch>::Node::~Node();
template ServerRoom<Switch>::Node* ServerRoom<Switch>::get_node(ServerRoom<Switch>*, int);
template ServerRoom<Switch>::ServerRoom();
template ServerRoom<Switch>::ServerRoom(Switch&);
template ServerRoom<Switch>::~ServerRoom();
template ServerRoom<Switch>& ServerRoom<Switch>::operator--(int);
template Switch* ServerRoom<Switch>::operator[](int);
template bool operator== (const ServerRoom<Switch>&, const ServerRoom<Switch>&);
template bool operator!= (const ServerRoom<Switch>&, const ServerRoom<Switch>&);
template void ServerRoom<Switch>::add(Switch&);
template std::vector<Switch*> ServerRoom<Switch>::get_vector();
template void ServerRoom<Switch>::seek(int);
template void ServerRoom<Switch>::sort();
template std::vector <Switch*> ServerRoom<Switch>::search(MAC_Address);
template std::vector <Switch*> ServerRoom<Switch>::search(int, int);
template int ServerRoom<Switch>::size();
template int ServerRoom<Switch>::cli_total();
#pragma endregion

#pragma region Instancing for Gateway
template class ServerRoom<Gateway>;
template ServerRoom<Gateway>::Node::Node(Gateway*);
template ServerRoom<Gateway>::Node::~Node();
template ServerRoom<Gateway>::Node* ServerRoom<Gateway>::get_node(ServerRoom<Gateway>*, int);
template ServerRoom<Gateway>::ServerRoom();
template ServerRoom<Gateway>::ServerRoom(Gateway&);
template ServerRoom<Gateway>::~ServerRoom();
template ServerRoom<Gateway>& ServerRoom<Gateway>::operator--(int);
template Gateway* ServerRoom<Gateway>::operator[](int);
template bool operator== (const ServerRoom<Gateway>&, const ServerRoom<Gateway>&);
template bool operator!= (const ServerRoom<Gateway>&, const ServerRoom<Gateway>&);
template void ServerRoom<Gateway>::add(Gateway&);
template std::vector<Gateway*> ServerRoom<Gateway>::get_vector();
template void ServerRoom<Gateway>::seek(int);
template void ServerRoom<Gateway>::sort();
template std::vector <Gateway*> ServerRoom<Gateway>::search(MAC_Address);
template std::vector <Gateway*> ServerRoom<Gateway>::search(int, int);
template std::vector <Gateway*> ServerRoom<Gateway>::search(std::string, SearchMode);
template int ServerRoom<Gateway>::size();
template int ServerRoom<Gateway>::cli_total();
#pragma endregion

#pragma region Instancing for Router
template class ServerRoom<Router>;
template ServerRoom<Router>::Node::Node(Router*);
template ServerRoom<Router>::Node::~Node();
template ServerRoom<Router>::Node* ServerRoom<Router>::get_node(ServerRoom<Router>*, int);
template ServerRoom<Router>::ServerRoom();
template ServerRoom<Router>::ServerRoom(Router&);
template ServerRoom<Router>::~ServerRoom();
template ServerRoom<Router>& ServerRoom<Router>::operator--(int);
template Router* ServerRoom<Router>::operator[](int);
template bool operator== (const ServerRoom<Router>&, const ServerRoom<Router>&);
template bool operator!= (const ServerRoom<Router>&, const ServerRoom<Router>&);
template void ServerRoom<Router>::add(Router&);
template std::vector<Router*> ServerRoom<Router>::get_vector();
template void ServerRoom<Router>::seek(int);
template void ServerRoom<Router>::sort();
template std::vector <Router*> ServerRoom<Router>::search(MAC_Address);
template std::vector <Router*> ServerRoom<Router>::search(int, int);
template std::vector <Router*> ServerRoom<Router>::search(std::string, SearchMode);
template int ServerRoom<Router>::size();
template int ServerRoom<Router>::cli_total();
#pragma endregion

/**
* Конструктор для структуры
* 
* @param указатель на данные для хранения
*/
template <typename T>
ServerRoom<T>::Node::Node(T* device) {
    this->device = device;
    this->next = nullptr;
    this->prev = nullptr;
}

/**
* Деструктор для структуры. При удалении текущего элемента 
* также удаляет и следующий за ним, а также связь с предыдущим
*/
template <typename T>
ServerRoom<T>::Node::~Node() {
    if (device) delete device; // TODO: Нужно ли удалять девайс в принципе?
    if (next) delete next;
    if (prev != nullptr) prev->next = nullptr;
}

/**
* Конструктор по умолчанию - создаёт пустую первую "полку"
*/
template <typename T> 
ServerRoom<T>::ServerRoom() {
    this->first = nullptr;
    this->last = this->first;
}

/**
* Конструктор по умолчанию - создаёт первую "полку" с объектом T
* 
* @param ссылка на добавляемое устройство
*/
template <typename T>
ServerRoom<T>::ServerRoom(T& device) {
    this->first = new Node(&device);
    this->last = this->first;
}

/**
* Копирующий конструктор
*
* @param ссылка на добавляемое устройство
*/
template <typename T>
ServerRoom<T>::ServerRoom(const ServerRoom<T>& copy) {
    this->first = nullptr;
    this->last = this->first;
    Node* current = copy.first;
    while (current != nullptr) {
        if (current->device != nullptr)
            this->add(*current->device);
        current = current->next;
    }
}

/**
* Декоструктор - удаляет все структуры-"полки"
*/
template <typename T>
ServerRoom<T>::~ServerRoom() {
    if (first) delete first;
    if (last) delete last;
}

/**
* Метод возвращает указатель на "полку" под некоторым индексом.
*
* @param указатель на ServerRoom
* @param индекс
* @return указатель на "полку"
*/
template <typename T>
typename ServerRoom<T>::Node* ServerRoom<T>::get_node(ServerRoom<T>* room, int index) {
    Node* node = room->first;
    for (int i = 0; i < index; i++) {
        if (node != nullptr)
            node = node->next;
        else
            throw std::range_error("Index of element was out of range: " + index + '/' + i);
    }
    return node;
}

/*
* Оператор удаляет последнее количество "полок".
*
* @param количество удаляемого
* @return текущий экземпляр ServerRoom
*/
template <typename T>
ServerRoom<T>& ServerRoom<T>::operator--(int count) {
    this->seek(count);
    return *this;
}

/**
* Оператор возвращает указатель на объект T указанной "полки".
*
* @param индекс элемента
* @return указатель на элемент
*/
template <typename T>
T* ServerRoom<T>::operator[](int index) {
    try {
        Node* node = get_node(this, index);
        return node->device;
    }
    catch (std::range_error err) {
        throw std::range_error(err.what());
    }
}

/**
* Оператор проверяет равны ли две комнаты по размеру
*
* @param первый сравниваемый экземпляр ServerRoom
* @param второй сравниваемый экземпляр ServerRoom
* @return булево значение - результат сравнения
*/
template <typename T>
bool operator==(const ServerRoom<T>& first, const ServerRoom<T>& second) {
    return first.size() == second.size();
}

/**
 * Оператор проверяет различны ли две комнаты по размеру
 *
 * @param первый сравниваемый экземпляр ServerRoom
 * @param второй сравниваемый экземпляр ServerRoom
 * @return булево значение - результат сравнения
 */
template <typename T>
bool operator!=(const ServerRoom<T>& first, const ServerRoom<T>& second) {
    return first.size() != second.size();
}

/**
 * Метод добавляет элемент в конец комнаты
 *
 * @param ссылка на добавляемый элемент
 */
template <typename T>
void ServerRoom<T>::add(T& device) {
    if (this->last == nullptr) {
        this->last = new Node(&device);
        this->first = this->last;
    }
    else {
        this->last->next = new Node(&device);
        this->last->next->prev = this->last;
        this->last = this->last->next;
    }
}

template <typename T>
std::vector<T*> ServerRoom<T>::get_vector() {
    std::vector<T*> pointers = {};
    Node* current = this->first;
    while (current != nullptr) {
        if (current->device != nullptr)
            pointers.emplace_back(current->device);
        current = current->next;
    }
    return pointers;
}

/**
 * Метод удаляет некоторое количество элементов с конца
 *
 * @param количество удаляемых элементов
 */
template <typename T>
void ServerRoom<T>::seek(int count) {
    if (count <= 0)
        throw std::invalid_argument("Count must be positive and bigger than zero");
    do {
        if (this->first == this->last) {
            if (this->last != nullptr) delete this->last;
            this->first = nullptr;
            this->last = nullptr;
        }
        else {
            Node* prev = get_node(this, size() - 2);
            prev->next = nullptr;
            delete this->last;
            this->last = prev;
        }
        count--;
    } while (count > 0);
}

/**
 * Метод сортирует хранимые объекты методом пузырька
 */
template <typename T>
void ServerRoom<T>::sort() {
    int room_size = size();
    for (int i = 0; i < room_size; i++)
        for (int j = 0; j < room_size - 1 - i; j++) {
            Node* current = get_node(this, j);
            if (*(current->device) > *(current->next->device)) { // Использован оператор больше
                T* tmp;
                tmp = current->next->device;
                current->next->device = current->device;
                current->device = tmp;
            }
        }
}

/**
* Метод поиска экземпляра по MAC адресу
* 
* @param address объекта
* @return вектор указатель на найденные объекты
*/
template<typename T>
std::vector<T*> ServerRoom<T>::search(MAC_Address address) {
    int count = 0;
    std::vector<T*> vec = {};
    Node* current = this->first;

    while (current != nullptr) {
        if (current->device != nullptr)
            if (current->device->get_address() == address)
                vec.emplace_back(current->device);
        current = current->next;
    }
    return vec;
}

/**
* Метод поиска экземпляра по диапазону клиентов
*
* @param address объекта
* @return вектор указатель на найденные объекты
*/
template<typename T>
std::vector <T*> ServerRoom<T>::search(int start, int end) {
    int count = 0;
    std::vector<T*> vec = {};
    Node* current = this->first;

    while (current != nullptr) {
        if (current->device != nullptr)
            if (start < current->device->clients_count() < end)
                vec.emplace_back(current->device);
        current = current->next;
    }
    return vec;
}

/**
* Метод поиска экземпляра WLRepeater по диапазону клиентов
*
* @param искомая строка
* @param режим поиска
* @return вектор указатель на найденные объекты
*/
template<>
std::vector <WLRepeater*> ServerRoom<WLRepeater>::search(std::string str, SearchMode mode) {
    int count = 0;
    std::vector<WLRepeater*> vec = {};
    std::string search_str = "";
    Node* current = this->first;

    while (current != nullptr) {
        if (mode == SearchMode::SSID) search_str = current->device->get_ssid();
        if (current->device != nullptr)
            if (search_str == str)
                vec.emplace_back(current->device);
        current = current->next;
    }
    return vec;
}

/**
* Метод поиска экземпляра Gateway по диапазону клиентов
*
* @param искомая строка
* @param режим поиска
* @return вектор указатель на найденные объекты
*/
template<>
std::vector <Gateway*> ServerRoom<Gateway>::search(std::string str, SearchMode mode) {
    int count = 0;
    std::vector<Gateway*> vec = {};
    std::string search_str = "";
    Node* current = this->first;

    while (current != nullptr) {
        if (mode == SearchMode::Protocol) search_str = current->device->get_protocol();
        if (current->device != nullptr)
            if (search_str == str)
                vec.emplace_back(current->device);
        current = current->next;
    }
    return vec;
}

/**
* Метод поиска экземпляра Router по диапазону клиентов
*
* @param искомая строка
* @param режим поиска
* @return вектор указатель на найденные объекты
*/
template<>
std::vector <Router*> ServerRoom<Router>::search(std::string str, SearchMode mode) {
    int count = 0;
    std::vector<Router*> vec = {};
    std::string search_str = "";
    Node* current = this->first;

    while (current != nullptr) {
        if (mode == SearchMode::Protocol) search_str = current->device->get_protocol();
        if (mode == SearchMode::SSID) search_str = current->device->get_ssid();
        if (current->device != nullptr)
            if (search_str == str)
                vec.emplace_back(current->device);
        current = current->next;
    }
    return vec;
}

/**
* Метод поиска экземпляра по статусу WPS
*
* @param address объекта
* @return вектор указатель на найденные объекты
*/
std::vector<Router*> ServerRoom<Router>::search(bool wps) {
    int count = 0;
    std::vector<Router*> vec = {};
    Node* current = this->first;

    while (current != nullptr) {
        if (current->device != nullptr)
            if (current->device->is_wps() != wps)
                vec.emplace_back(current->device);
        current = current->next;
    }
    return vec;
}

/**
* Метод поиска экземпляра по статусу WPS
*
* @param address объекта
* @return вектор указатель на найденные объекты
*/
std::vector<WLRepeater*> ServerRoom<WLRepeater>::search(bool wps) {
    int count = 0;
    std::vector<WLRepeater*> vec = {};
    Node* current = this->first;

    while (current != nullptr) {
        if (current->device != nullptr)
            if (current->device->is_wps() != wps)
                vec.emplace_back(current->device);
        current = current->next;
    }
    return vec;
}

/**
* Функция возвращает количество элементов в комнате
* 
* @return количество элементов
*/
template <typename T>
int ServerRoom<T>::size() {
    int count = 0;
    Node* current = this->first;
    while (current != nullptr) {
        if (current->device != nullptr)
            count++;
        current = current->next;
    }
    return count;
}

/**
* Функция возвращает количество клиентов 
* по всем устроствам в комнате
*
* @return количество клиентов
*/
template <typename T>
int ServerRoom<T>::cli_total() {
    int count = 0;
    Node* current = this->first;
    while (current != nullptr) {
        if (current->device != nullptr)
            count += current->device->clients_count();
        current = current->next;
    }
    return count;
}
