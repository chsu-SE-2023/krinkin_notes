#include "data_center.h"
#include "../devices/net_device.h"
#include "../misc/address.h"
#include <iostream>

// Инстанцирование для ServerRoom
template class DataCenter<ServerRoom>;
template DataCenter<ServerRoom>::Node::Node(ServerRoom*);
template DataCenter<ServerRoom>::Node::~Node();
template DataCenter<ServerRoom>::Node* DataCenter<ServerRoom>::get_node(DataCenter<ServerRoom>*, int);
template DataCenter<ServerRoom>::DataCenter();
template DataCenter<ServerRoom>::DataCenter(ServerRoom&);
template DataCenter<ServerRoom>::~DataCenter();
template DataCenter<ServerRoom>& DataCenter<ServerRoom>::operator--(int);
template ServerRoom* DataCenter<ServerRoom>::operator[](int);
template bool operator== (const DataCenter<ServerRoom>&, const DataCenter<ServerRoom>&);
template bool operator!= (const DataCenter<ServerRoom>&, const DataCenter<ServerRoom>&);
template void DataCenter<ServerRoom>::add(ServerRoom&);
template void DataCenter<ServerRoom>::seek(int);
template void DataCenter<ServerRoom>::sort();
template ServerRoom* DataCenter<ServerRoom>::search(MAC_Address);
template int DataCenter<ServerRoom>::size();

/**
* Конструктор для структуры
* 
* @param указатель на данные для хранения
*/
template <typename T>
DataCenter<T>::Node::Node(T* device) {
    this->device = device;
    this->next = nullptr;
    this->prev = nullptr;
}

/**
* Деструктор для структуры. При удалении текущего элемента 
* также удаляет и следующий за ним, а также связь с предыдущим
*/
template <typename T>
DataCenter<T>::Node::~Node() {
    if (device) delete device; // Нужно ли удалять девайс в принципе?
    if (next) delete next;
    if (prev != nullptr) prev->next = nullptr;
}

/**
* Конструктор по умолчанию - создаёт пустую первую "полку"
*/
template <typename T> 
DataCenter<T>::DataCenter() {
    this->first = new Node(nullptr);
    this->last = this->first;
}

/**
* Конструктор по умолчанию - создаёт первую "полку" с объектом T
* 
* @param ссылка на добавляемое устройство
*/
template <typename T>
DataCenter<T>::DataCenter(T& device) {
    this->first = new Node(&device);
    this->last = this->first;
}

/**
* Декоструктор - удаляет все структуры-"полки"
*/
template <typename T>
DataCenter<T>::~DataCenter() {
    if (first) delete first;
    if (last) delete last;
}

/**
* Метод возвращает указатель на "полку" под некоторым индексом.
*
* @param указатель на DataCenter
* @param индекс
* @return указатель на "полку"
*/
template <typename T>
typename DataCenter<T>::Node* DataCenter<T>::get_node(DataCenter<T>* room, int index) {
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
* @return текущий экземпляр DataCenter
*/
template <typename T>
DataCenter<T>& DataCenter<T>::operator--(int count) {
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
T* DataCenter<T>::operator[](int index) {
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
* @param первый сравниваемый экземпляр DataCenter
* @param второй сравниваемый экземпляр DataCenter
* @return булево значение - результат сравнения
*/
template <typename T>
bool operator==(const DataCenter<T>& first, const DataCenter<T>& second) {
    return first.size() == second.size();
}

/**
 * Оператор проверяет различны ли две комнаты по размеру
 *
 * @param первый сравниваемый экземпляр DataCenter
 * @param второй сравниваемый экземпляр DataCenter
 * @return булево значение - результат сравнения
 */
template <typename T>
bool operator!=(const DataCenter<T>& first, const DataCenter<T>& second) {
    return first.size() != second.size();
}

/**
 * Метод добавляет элемент в конец комнаты
 *
 * @param ссылка на добавляемый элемент
 */
template <typename T>
void DataCenter<T>::add(T& device) {
    if (this->last->device == nullptr) {
        this->last->device = &device;
    }
    else {
        this->last->next = new Node(&device);
        this->last->next->prev = this->last;
        this->last = this->last->next;
    }
}

/**
 * Метод удаляет некоторое количество элементов с конца
 *
 * @param количество удаляемых элементов
 */
template <typename T>
void DataCenter<T>::seek(int count) {
    if (count <= 0)
        throw std::invalid_argument("Count must be positive and bigger than zero");
    if (this->first == this->last) {
        this->first = nullptr;
        this->last = nullptr;
    }
    else {
        do {
            Node* prev = get_node(this, size() - 1);
            prev->next = nullptr;
            delete this->last;
            this->last = prev;
            count--;
        } while (count > 0);
    }
}

/**
 * Метод сортирует экземпляры NetDevice по количеству поключенных устройств по возрастанию
 */
template <>
void DataCenter<NetDevice>::sort() {
    int room_size = size();
    for (int i = 0; i < room_size; i++)
        for (int j = 0; j < room_size - 1 - i; j++) {
            Node* current = get_node(this, j);
            // TODO: У NetDevice нет оператора >
            //if (*(current->device) > *(current->next->device)) { // Использован оператор больше
            //    NetDevice* tmp;
            //    tmp = current->next->device;
            //    current->next->device = current->device;
            //    current->device = tmp;
            //}
        }
}

/**
* Метод поиска экземпляра NetDevice по MAC адресу
* 
* @param address объекта NetDevice
* @return указатель на найденный объект или nullptr если объект не найден
*/
template<>
NetDevice* DataCenter<NetDevice>::search(MAC_Address address) {
    Node* current = this->first;
    while (current->next != nullptr) {
        if (current->device->get_address() != address) {
            if (current->next != nullptr)
                current = current->next;
            continue;
        }
        return current->device;
    }
    return nullptr;
}

/**
* Функция возвращает количество элементов в комнате
* 
* @return количество элементов
*/
template <typename T>
int DataCenter<T>::size() {
    int count = 0;
    Node* current = this->first;
    if (current != nullptr && current->device != nullptr) {
        count++;
        while (current->next != nullptr) {
            if (current != nullptr)
                current = current->next;
            count++;
        }
    }
    return count;
}
