from abc import ABC, abstractmethod
from random import randint
from typing import List, Self
from enum import Enum

"""
Иерархия классов сетевых устройств

  NetDevice
      ^
      |
   Repeater *- Client, MacAddress
      ^           *
      |           |
   Switch      MacAddress
      ^
      |
   Gateway
      ^
      |
    Router

^ - наследование
* - композиция
"""


class MacAddress:
    """
    Класс, представляющий тип MAC адреса сетевого устройства
    """

    __values: List[int]

    def __init__(self, values=None):
        """
        Конструктор класса. Если значения не заданы, то они
        будут сгенерированы
        :param values: конкретные значения
        """
        if values is None or len(values) != 6:
            self.generate()
        else: self.__values = values

    def __str__(self) -> str:
        """
        Преобразование типа к строке
        :return: строка
        """
        return ":".join([hex(x)[2:].upper() for x in self.__values])
    
    def __eq__(a, b) -> bool:
        """
        Преобразование типа к строке
        :return: результат сравнения
        """
        return a.__values == b.__values

    def generate(self) -> Self:
        """
        Создаёт случайный MAC адрес
        :return: объект класса
        """
        self.__values = [ randint(0, 255) for _ in range(6) ]
        return self


class ClientType(Enum):
    """
    Перечисление типов клиентов
    """
    WIRED = 'wired' # Проводной
    WIRELESS = 'wireless'  # Беспроводной


class Client:

    """
    Класс, представляющий клиента сетевых устройств
    """

    __name: str
    __address: MacAddress
    __packets: bytes
    __type: ClientType

    def __init__(self, name, type: ClientType = ClientType.WIRED):
        """
        Конструктор класса
        :param name: имя клиента
        :param type: тип клиента (ClientType.WIRED если не указано)
        """
        self.__name = name
        self.__address = MacAddress()
        self.__type = type
        self.__packets = bytes()

    def __str__(self):
        """
        Преобразование типа к строке
        :return: строка
        """
        return (f"name: {self.__name}\n"
                f"address: {self.__address}\n"
                f"packets: {self.__packets}\n"
                f"type: {self.__type}\n")

    @property
    def address(self) -> MacAddress:
        """
        Геттер MAC-адреса
        :return: MAC-адрес
        """
        return self.__address
    
    @property
    def name(self) -> str:
        """
        Геттер имени
        :return: имя клиента
        """
        return self.__name
    
    @property
    def packets(self) -> bytes:
        """
        Геттер пакетов
        :return: пакеты
        """
        return self.__packets
    
    @property
    def type(self) -> ClientType:
        """
        Геттер типа
        :return: тип клиента
        """
        return self.__type
    
    @address.setter
    def address(self, value: MacAddress):
        """
        Сеттер адреса
        :param value: новый MAC-адрес
        """
        self.__address = value

    @packets.setter
    def packets(self, value: bytes):
        """
        Сеттер пакетов
        :param value: пакеты
        """
        self.__packets = value

    @name.setter
    def name(self, value: str):
        """
        Сеттер имени
        :param value: новое имя
        """
        self.__name = value

    @type.setter
    def type(self, value: ClientType):
        """
        Сеттер типа
        :param value: новый тип
        """
        self.__type = value

    def send_to(self, device):
        """
        Метод для отправки пакетов на определённое сетевое устройство
        :param device: целевое сетевое устройство
        """
        device.packets = self.__packets

    def receive_from(self, device):
        """
        Метод для принятия пакетов с определённого сетевого устройства
        :param device: целевое сетевое устройство
        """
        self.__packets = device.packets


class NetDevice(ABC):

    """
    Абстрактный класс, представляющий сетевое устройство
    """

    @abstractmethod
    def reset(self): pass

    @abstractmethod
    def __str__(self) -> str: pass

    @abstractmethod
    def __eq__(a, b) -> bool: pass

    @abstractmethod
    def clients_count(self) -> int: pass

    @property
    @abstractmethod
    def address(self) -> MacAddress: pass
    
    @abstractmethod
    def package_size(self) -> int: pass

    @property
    @abstractmethod
    def packets(self) -> bytes: pass

    @packets.setter
    @abstractmethod
    def packets(self, data: bytes): pass

    @address.setter
    @abstractmethod
    def address(self, value): pass


class Repeater(NetDevice):

    """
    Сетевое устройство повторитель. Является базовым классов
    в иерархии
    """

    __address: MacAddress
    __packets: bytes
    _clients: List[Client]

    def __init__(self, address: MacAddress = MacAddress()):
        """
        Конструктор класса
        """
        self.reset()
        self.__address = address

    def reset(self):
        """
        Метод, устанавливающий начальные значения
        """
        self.__address = MacAddress()
        self.__packets = bytes()
        self._clients = []

    def __str__(self) -> str:
        """
        Преобразование класса в строку с информацией о
        сетевом устройстве
        :return: строка информации
        """
        return (f'{self.__class__.__name__}:\n'
                f'    address: {self.__address}\n'
                f'    packets: {self.__packets}\n'
                f'    clients: {self.clients_count()}')
    
    def __eq__(a, b) -> bool:
        """
        Перегрузка оператора сравнения
        :param a: первый объект класса
        :param b: второй объект класса
        :return: результат сравнения
        """
        return a.address == b.address
    
    @staticmethod
    def localized_name():
        """
        Статический метод с именем устройства на русском языке
        :return: локализованное имя устройства
        """
        return "Повторитель"
    
    def connect(self, client: Client):
        """
        Метод подключения клиента к устройству
        :param client: подключаемый клиент
        """
        if len(self._clients) == 0:
            self._clients.append(client)

    def disconnect(self, client: Client):
        """
        Метод отключения клиента к устройству
        :param client: отключаемый клиент
        """
        if client in self._clients:
            self._clients.remove(client)

    def clients_count(self) -> int:
        """
        :return: количество подключенных устройств
        """
        return len(self._clients)
    
    def package_size(self) -> int:
        """
        :return: размер хранимых пакетов
        """
        return len(self.__packets)

    @property
    def address(self) -> MacAddress:
        """
        Геттер для MAC-адреса
        :return: MAC-адрес устройства
        """
        return self.__address
    
    @property
    def packets(self) -> bytes:
        """
        Геттер для передаваемых пакетов
        :return: передаваемые пакеты
        """
        return self.__packets

    @address.setter
    def address(self, value):
        """
        Сеттер MAC-адреса
        :return: новый MAC-адрес
        """
        self.__address = value

    @packets.setter
    def packets(self, data: bytes):
        """
        Сеттер передаваемых пакетов
        :return: передаваемые пакеты
        """
        self.__packets = data


class Switch(Repeater):

    """
    Сетевое устройство разветвитель
    """

    __cli_cap: int

    def __init__(self, address: MacAddress = MacAddress(), capacity: int = 4):
        """
        Конструктор класса
        """
        self.reset()
        super().__init__(address)
        self.__cli_cap = capacity

    def reset(self):
        """
        Метод, устанавливающий начальные значения
        """
        self.__cli_cap = 4
        super().reset()
    
    def __str__(self):
        """
        Преобразование класса в строку с информацией о
        сетевом устройстве. Использует информацию из иерархии выше
        :return: строка информации
        """
        return super().__str__() + f'\n    capacity: {self.__cli_cap}'
    
    @staticmethod
    def localized_name():
        """
        Статический метод с именем устройства на русском языке
        :return: локализованное имя устройства
        """
        return "Разветвитель"
    
    @property
    def capacity(self) -> int:
        """
        Геттер вместимости сетевого устройства (у устройств в
        иерархии выше она условно равна 1)
        :return: вместимость сетевого устройства
        """
        return self.__cli_cap
    
    @capacity.setter
    def capacity(self, value: int):
        """
        Сеттер вместимости сетевого устройства
        :param value: вместимость сетевого устройства
        """
        self.__cli_cap = value

    def connect(self, client):
        """
        Переопределение метода подключения к сетевому
        устройству с проверкой вместимости
        :param client: подключаемый клиент
        """
        if len(self._clients) < self.__cli_cap:
            self._clients.append(client)


class Gateway(Switch):

    """
    Сетевое устройство шлюз
    """

    __protocol: str

    def __init__(self, address: MacAddress = MacAddress(),
                 capacity: int = 4, protocol: str = "raw"):
        """
        Конструктор класса
        """
        self.reset()
        super().__init__(address, capacity)
        self.__protocol = protocol

    def reset(self):
        """
        Метод, устанавливающий начальные значения
        """
        self.__protocol = "raw"
        super().reset()

    def __str__(self) -> str:
        """
        Преобразование класса в строку с информацией о
        сетевом устройстве. Использует информацию из иерархии выше
        :return: строка информации
        """
        return super().__str__() + f'\n    protocol: {self.__protocol}'

    @staticmethod
    def localized_name():
        """
        Статический метод с именем устройства на русском языке
        :return: локализованное имя устройства
        """
        return "Шлюз"

    @property
    def protocol(self) -> str:
        """
        Геттер протокола передачи данных сетевого устройства
        :return: наименование протокола передачи данных
        """
        return self.__protocol
    
    @protocol.setter
    def protocol(self, value: str):
        """
        Сеттер протокола передачи данных сетевого устройства
        :param value: имя нового протокола
        """
        self.__protocol = value


class Router(Gateway):

    """
    Сетевое устройство маршрутизатор
    """

    __wps: bool
    __ssid: str
    __passwd: str

    def __init__(self, address: MacAddress = MacAddress(), capacity: int = 4,
                 protocol: str = "raw", ssid: str = "Default", passwd: str = "admin"):
        """
        Конструктор класса
        """
        self.reset()
        super().__init__(address, capacity, protocol)
        self.__ssid = ssid
        self.__passwd = passwd


    def reset(self):
        """
        Метод, устанавливающий начальные значения
        """
        self.__wps = False
        self.__ssid = "Default"
        self.__passwd = "admin"
        return super().reset()

    def __str__(self) -> str:
        """
        Преобразование класса в строку с информацией о
        сетевом устройстве. Использует информацию из иерархии выше
        :return: строка информации
        """
        return (super().__str__() +
                f'\n    wps mode: {"yes" if self.__wps else "no"}\n'
                f'    SSID: {self.__ssid}\n'
                f'    Password: {"*"*len(self.__passwd)}')

    @property
    def ssid(self):
        """
        Геттер для имени беспроводной сети
        :return: имя беспроводной сети
        """
        return self.__ssid
    
    @ssid.setter
    def ssid(self, value: str):
        """
        Сеттер для имени беспроводной сети
        :param value: новое имя беспроводной сети
        """
        self.__ssid = value

    @staticmethod
    def localized_name():
        """
        Статический метод с именем устройства на русском языке
        :return: локализованное имя устройства
        """
        return "Маршрутизатор"

    def is_wps(self) -> bool:
        """
        Метод возвращающий находится ли устройство в режиме
        подключения по WPS
        :return: включен ли WPS
        """
        return self.__wps
    
    def wps_init(self):
        """
        Метод переводит устройство в режим подключения по WPS
        (режим позволяет подключиться к беспроводной сети без
        пароля)
        """
        self.__wps = True

    def connect(self, client: Client, ssid: str = None, passwd: str = None):

        """
        Переопределение метода подключения клиента. Если клиент беспроводной и
        не указан пароль, то будет использоваться режим WPS (если включен),
        после чего режим будет отключен.
        :param client: подключаемый клиент
        :param ssid: имя беспроводной сети
        :param passwd: пароль от беспроводной сети
        """
        if client.type == ClientType.WIRED:
            super().connect(client)

        if client.type == ClientType.WIRELESS:
            if (ssid == self.__ssid and passwd == self.__passwd) or self.__wps:
                super().connect(client)
                self.__wps = False

    def change_passwd(self, old: str, new: str):
        """
        Метод смены пароля
        :param old: старый пароль
        :param new: новый пароль
        """
        if old == self.__passwd:
            self.__passwd = new


if __name__ == "__main__":

    print("----- Создание MAC-Адреса -----")
    print(MacAddress())
    print("\n----- Генерация MAC-Адреса -----")
    print(MacAddress().generate())

    print("\n----- Создание клиента -----")
    print(Client("Cool guy", ClientType.WIRELESS))

    print("\n----- Создание повторителя -----")
    print(Repeater(MacAddress()))

    print("\n----- Создание разветвителя -----")
    print(Switch(MacAddress(), 12))

    print("\n----- Создание шлюза -----")
    print(Gateway(MacAddress(), 12, "https"))

    print("\n----- Создание роутера -----")
    print(Router(MacAddress(), 12, "https", "MyWifi", "qwerty"))

    print("\n----- Подключение проводного клиента -----")
    r = Router()
    r.connect(Client("some_name"))
    print(r)

    print("\n----- Подключение беспроводного клиента -----")
    r = Router(ssid="TestSSID", passwd="Str0ngPasSw0rd")
    r.connect(Client("some_name", ClientType.WIRELESS), "TestSSID", "Str0ngPasSw0rd")
    print(r)

    print("\n----- Подключение по WPS -----")
    r = Router(ssid="TestSSID", passwd="Str0ngPasSw0rd")
    r.wps_init()
    r.connect(Client("some_name", ClientType.WIRELESS))
    print(r)

    print("\n----- Сравнение адресов -----")
    a1 = MacAddress([104, 87, 34, 56, 156, 203])
    a2 = MacAddress([104, 87, 34, 56, 156, 203])
    print(a1, "==" , a2, '-', a1 == a2)
    a1.generate(); a2.generate()
    print(a1, "==" , a2, '-', a1 == a2)

    print("\n----- Сравнение устройств -----")
    r1 = Router(MacAddress([104, 87, 34, 56, 156, 203]))
    r2 = Router(MacAddress([104, 87, 34, 56, 156, 203]))
    print('* Устройство 1: \n', r1)
    print('* Устройство 2: \n', r2)
    print('* Равны -', r1 == r2)

    r1 = Router(); r2 = Router()
    print('* Устройство 1: \n', r1)
    print('* Устройство 2: \n', r2)
    print('* Равны -', r1 == r2)

    print("\n----- Пересылка пакетов -----")

    c = Client("Mr. Sender")
    rep = Repeater()
    rep.connect(c)
    
    print("* Отправка")
    c.packets = bytes('Some important internet data', encoding='utf-8')
    c.send_to(rep)
    print(rep)

    print("* Получение")
    c.packets = b''
    c.receive_from(rep)
    print(c.packets)
  