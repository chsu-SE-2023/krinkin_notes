#include "net_room.h"
#include "net_device.h"
#include <iostream>

// Инстанцирование для NetDevice
template class ServerRoom<NetDevice>;
template ServerRoom<NetDevice>::ServerRoom();
template ServerRoom<NetDevice>::ServerRoom(NetDevice&);
template ServerRoom<NetDevice>::~ServerRoom<NetDevice>();
template ServerRoom<NetDevice>& ServerRoom<NetDevice>::operator+(NetDevice&);
template ServerRoom<NetDevice>& ServerRoom<NetDevice>::operator--(int);
template const NetDevice* ServerRoom<NetDevice>::operator[](int);
template void ServerRoom<NetDevice>::sort();
template int ServerRoom<NetDevice>::get_size();

template <typename T> 
ServerRoom<T>::ServerRoom() {
    /*
     * Конструктор по умолчанию - создаёт пустую первую "полку".
     */
    this->first = new Shelf;
    this->first->device = nullptr;
    this->first->next = nullptr;
    this->last = this->first;
}

template <typename T>
ServerRoom<T>::ServerRoom(T& device) {
    /*
     * Конструктор по умолчанию - создаёт первую "полку" с объектом T.
     */
    this->first = new Shelf;
    this->first->device = &device;
    this->first->next = nullptr;
    this->last = this->first;
}

template <typename T>
ServerRoom<T>::~ServerRoom() {
    /*
     * Декоструктор - удаляет все структуры-"полки", не затронув хранящиеся
     * в них объекты типа Switch.
     */
    Shelf* current = this->first;
    Shelf* to_delete = nullptr;
    if (current != nullptr) {
        while (current->next != nullptr) {
            to_delete = current;
            current = current->next;
            delete to_delete;
        }
    }
    delete current;
}

template <typename T>
typename ServerRoom<T>::Shelf* ServerRoom<T>::get_shelf(ServerRoom<T>* room, int shelf_id) {
    /*
     * Функция возвращает указатель на "полку" под некоторым номером.
     * (приватна)
     */
    Shelf* shelf = room->first;
    for (int i = 0; i < shelf_id; i++) {
        if (shelf != nullptr)
            shelf = shelf->next;
    }
    return shelf;
}

template <typename T>
ServerRoom<T>& ServerRoom<T>::operator+(T& device) {
    /*
     * Оператор добавляет "полку" в конец комнаты.
     */
    this->add(device);
    return *this;
}

template <typename T>
ServerRoom<T>& ServerRoom<T>::operator--(int count) {
    /*
    * Оператор удаляет последнее количество "полок".
    */
    this->seek(count);
    return *this;
}

template <typename T>
const T* ServerRoom<T>::operator[](int index) {
    /*
     * Оператор возвращает указатель на объект T указанной "полки".
     */
    Shelf* shelf = get_shelf(this, index);
    return shelf->device;
}

bool operator==(ServerRoom<NetDevice>& first, ServerRoom<NetDevice>& second) {
    /*
     * Оператор проверяет равны ли две комнаты по размеру
     */
    return first.get_size() == second.get_size();
}

bool operator==(ServerRoom<NetDevice>& first, ServerRoom<NetDevice>& second) {
    /*
     * Оператор проверяет равны ли две комнаты по размеру
     */
    return first.get_size() == second.get_size();
}

std::ostream& operator<<(std::ostream& stream, ServerRoom<NetDevice>& room) {
    /*
     * Оператор печатает в консоль информацию обо всех устройствах в "комнате".
     */
    ServerRoom<NetDevice>::Shelf* shelf = room.first;
    int size = room.get_size();
    for (int i = 0; i < size; i++) {
        ServerRoom<NetDevice>::Shelf* shelf = room.get_shelf(&room, i);
        if (shelf != nullptr && shelf->device != nullptr) {
            stream << " * Shelf " << i << " device info:" << std::endl;
            shelf->device->print_info();
        } else
            stream << " * Shelf " << i << " is empty!" << std::endl;
        shelf = shelf->next;
    }
    return stream;
}

std::ostream& operator<<(std::ostream& stream, ServerRoom<NetDevice>& room) {
    /*
     * Оператор печатает в консоль информацию обо всех устройствах в "комнате".
     */
    ServerRoom<NetDevice>::Shelf* shelf = room.first;
    int size = room.get_size();
    for (int i = 0; i < size; i++) {
        ServerRoom<NetDevice>::Shelf* shelf = room.get_shelf(&room, i);
        if (shelf != nullptr && shelf->device != nullptr) {
            stream << " * Shelf " << i << " device info:" << std::endl;
            shelf->device->print_info();
        } else
            stream << " * Shelf " << i << " is empty!" << std::endl;
        shelf = shelf->next;
    }
    return stream;
}

// Инстанцирование для Switch
template <> 
void ServerRoom<NetDevice>::print(int shelf_id) {
    /*
     * Функция печатает в консоли информацию о "полке" и её содержимом.
     */
    Shelf* shelf = get_shelf(this, shelf_id);
    if (shelf != nullptr && shelf->device != nullptr) {
        std::cout << " * Shelf " << shelf_id << " device info:" << std::endl;
        shelf->device->print_info();
    } else
        std::cout << " * Shelf " << shelf_id << " is empty!" << std::endl;
}

// Инстанцирование для Router
template <> 
void ServerRoom<NetDevice>::print(int shelf_id) {
    /*
     * Функция печатает в консоли информацию о "полке" и её содержимом.
     */
    Shelf* shelf = get_shelf(this, shelf_id);
    if (shelf != nullptr && shelf->device != nullptr) {
        std::cout << " * Shelf " << shelf_id << " device info:" << std::endl;
        shelf->device->print_info();
    } else
        std::cout << " * Shelf " << shelf_id << " is empty!" << std::endl;
}

template <typename T>
void ServerRoom<T>::add(const T& device) {
    /*
     * Функция добавляет "полку" в конец комнаты.
     */
    if (this->last->device == nullptr) {
        this->last->device = &device;
    }
    else {
        this->last->next = new Shelf;
        this->last->next->device = &device;
        this->last = this->last->next;
        this->last->next = nullptr;
    }
}

template <typename T>
void ServerRoom<T>::seek(int count) {
    /*
     * Функция удаляет последнее количество "полок".
     */
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

template <>
void ServerRoom<NetDevice>::sort() {
    /*
     * Функция сортирует объекты T по количеству поключенных устройств 
     * по возрастанию.
     */
    int room_size = get_size();
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

template <>
void ServerRoom<NetDevice>::sort() {
    /*
     * Функция сортирует объекты T по количеству поключенных устройств
     * по возрастанию.
     */
    int room_size = get_size();
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

// Инстанцирование для NetDevice
template<> 
const NetDevice* ServerRoom<NetDevice>::search(std::array<int, 5>& address) {
    /*
     * Функция поиска объекта T по адресу. Возвращает адрес объекта
     * или nullptr, если объект не найден.
     */
    Shelf* current = this->first;
    while (current->next != nullptr) {
        for (int i = 0; i < address.size(); i++) {
            if (current->device->get_address()[i] != address[i]) {
                if (current->next != nullptr)
                    current = current->next;
                continue;
            }
        }
        return current->device;
    }
    return nullptr;
}

template <typename T>
int ServerRoom<T>::get_size() {
    /*
     * Функция возвращает количество "полок" в комнате.
     */
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

// Инстанцирование для NetDevice
template <>
const NetDevice** ServerRoom<NetDevice>::get_array() {
    /*
     * Функция возвращает массив указателей на объекты T.
     */
    int size = get_size();
    if (size == 0) throw std::length_error("Pointers array size is zero");
    const NetDevice** array = new const NetDevice *[size]();
    for (int i = 0; i < size; i++)
        array[i] = (*this)[i];
    return array;
}
