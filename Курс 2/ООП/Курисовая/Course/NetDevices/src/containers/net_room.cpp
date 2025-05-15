#include "net_room.h"
#include "../devices/net_device.h"
#include <iostream>

// Инстанцирование для NetDevice
template class ServerRoom<NetDevice>;
template ServerRoom<NetDevice>::ServerRoom();
template ServerRoom<NetDevice>::ServerRoom(const NetDevice&);
template ServerRoom<NetDevice>::~ServerRoom<NetDevice>();
template ServerRoom<NetDevice>& ServerRoom<NetDevice>::operator--(int);
template bool operator==(ServerRoom<NetDevice>& first, ServerRoom<NetDevice>& second);
template bool operator!=(ServerRoom<NetDevice>& first, ServerRoom<NetDevice>& second);
template NetDevice* ServerRoom<NetDevice>::operator[](int);
template void ServerRoom<NetDevice>::sort();
template int ServerRoom<NetDevice>::size();

/**
* Конструктор для структуры
* 
* @param указатель на данные для хранения
*/
template <typename T>
ServerRoom<T>::Shelf::Shelf(T* device) {
    this->device = device;
    this->next = nullptr;
    this->prev = nullptr;
}

/**
* Деструктор для структуры. При удалении текущего элемента 
* также удаляет и следующий за ним, а также связь с предыдущим
*/
template <typename T>
ServerRoom<T>::Shelf::~Shelf() {
    if (device) delete device; // Нужно ли удалять девайс в принципе?
    if (next) delete next;
    if (prev != nullptr) prev->next = nullptr;
}

/**
* Конструктор по умолчанию - создаёт пустую первую "полку"
*/
template <typename T> 
ServerRoom<T>::ServerRoom() {
    this->first = new Shelf(nullptr);
    this->last = this->first;
}

/**
* Конструктор по умолчанию - создаёт первую "полку" с объектом T
* 
* @param ссылка на добавляемое устройство
*/
template <typename T>
ServerRoom<T>::ServerRoom(const T& device) {
    this->first = new Shelf(&device);
    this->last = this->first;
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
typename ServerRoom<T>::Shelf* ServerRoom<T>::get_shelf(ServerRoom<T>* room, int index) {
    Shelf* shelf = room->first;
    for (int i = 0; i < index; i++) {
        if (shelf != nullptr)
            shelf = shelf->next;
        else
            throw std::range_error("Index of element was out of range: " + index + '/' + i);
    }
    return shelf;
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
        Shelf* shelf = get_shelf(this, index);
    }
    catch (std::range_error err) {
        throw std::range_error(err.what());
    }
    return shelf->device;
}

/**
* Оператор проверяет равны ли две комнаты по размеру
*
* @param первый сравниваемый экземпляр ServerRoom
* @param второй сравниваемый экземпляр ServerRoom
* @return булево значение - результат сравнения
*/
template <typename T>
bool operator==(ServerRoom<T>& first, ServerRoom<T>& second) {
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
bool operator!=(ServerRoom<T>& first, ServerRoom<T>& second) {
    return first.size() != second.size();
}

/**
 * Метод добавляет элемент в конец комнаты
 *
 * @param ссылка на добавляемый элемент
 */
template <typename T>
void ServerRoom<T>::add(const T& device) {
    if (this->last->device == nullptr) {
        this->last->device = &device;
    }
    else {
        this->last->next = new Shelf;
        this->last->next->device = &device;
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
void ServerRoom<T>::seek(int count) {
    if (count <= 0) 
        throw std::invalid_argument("Count must be positive and bigger than zero")
    if (this->first == this->last) {
        this->first = nullptr;
        this->last = nullptr;
    }
    else {
        do {
            Shelf* prev = get_shelf(this, get_size() - 1);
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
void ServerRoom<NetDevice>::sort() {
    int room_size = size();
    for (int i = 0; i < room_size; i++)
        for (int j = 0; j < room_size - 1 - i; j++) {
            Shelf* current = get_shelf(this, j);
            if (*(current->device) > *(current->next->device)) { // Использован оператор больше
                const NetDevice* tmp;
                tmp = current->next->device;
                current->next->device = current->device;
                current->device = tmp;
            }
        }
}

/**
* Метод поиска экземпляра NetDevice по MAC адресу
* 
* @param address объекта NetDevice
* @return указатель на найденный объект или nullptr если объект не найден
*/
template<>
NetDevice* ServerRoom<NetDevice>::search(MAC_Address address) {
    Shelf* current = this->first;
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
int ServerRoom<T>::size() {
    int count = 0;
    Shelf* current = this->first;
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
