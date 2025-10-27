from abc import ABC as Abstract, abstractmethod
from random import randint
from typing import List, Self
from enum import Enum

class MAC_Address:
    __values: List[int]

    def __init__(self, values = []):
        if len(values) != 6:
            self.generate()
        else: self.__values = values

    def __str__(self) -> str:
        return ":".join([hex(x)[2:].upper() for x in self.__values])
    
    def __eq__(a, b) -> bool:
        return a.__values == b.__values

    def generate(self) -> Self:
        self.__values = [ randint(0, 255) for _ in range(6) ]
        return self


class ClientType(Enum):
    WIRED = 'wired'
    WIRELESS = 'wireless'


class Client:

    __name: str
    __address: MAC_Address
    __packets: bytes
    __type: ClientType

    def __init__(self, name):
        self.__name = name
        self.__address = MAC_Address()
        self.__type = ClientType.WIRED

    @property
    def address(self) -> MAC_Address:
        return self.__address
    
    @property
    def name(self) -> str:
        return self.__name
    
    @property
    def type(self) -> ClientType:
        return self.__type
    
    @address.setter
    def address(self, value: MAC_Address):
        self.__address = value

    @name.setter
    def name(self, value: str):
        self.__name = value

    @type.setter
    def type(self, value: ClientType):
        self.__type = value

    def send_to(self, device):
        device.packets = self.__packets

    def receive_from(self, device):
        self.__packets = device.packets


class NetDevice(Abstract):

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
    def address(self) -> MAC_Address: pass
    
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

    __address: MAC_Address
    __packets: bytes
    __clients: List[Client]

    def __init__(self):
        self.reset()

    def reset(self):
        self.__address = MAC_Address()
        self.__packets = 0
        self.__clients = []

    def __str__(self) -> str:
        return (f'{self.__class__.__name__}:\n'
                f'    address: {self.__address}\n'
                f'    packets: {self.__packets}\n'
                f'    clients: {self.clients_count()}\n')
    
    def __eq__(a, b) -> bool:
        return a.address == b.address
    
    @staticmethod
    def localized_name():
        return "Повторитель"
    
    def connect(self, client: Client):
        if len(self.__clients) == 0:
            self.__clients.append(client)

    def disconnect(self, client: Client):
        if client in self.__clients:
            self.__clients.remove(client)

    def clients_count(self) -> int:
        return len(self.__clients)
    
    def package_size(self) -> int:
        return len(self.__clients)

    @property
    def address(self) -> MAC_Address:
        return self.__address
    
    @property
    def packets(self) -> bytes:
        return self.__packets

    @packets.setter
    def packets(self, data: bytes):
        self.__packets = data

    @address.setter
    def address(self, value):
        self.__address = value


class Switch(Repeater):

    __cli_cap: int

    def __init__(self):
        self.reset()
        super().__init__()

    def reset(self):
        self.__cli_cap = 4
        super().reset()
    
    def __str__(self):
        return super().__str__() + f'    capacity: {self.__cli_cap}\n'
    
    @staticmethod
    def localized_name():
        return "Разветвитель"
    
    @property
    def capacity(self) -> int:
        return self.__cli_cap
    
    @capacity.setter
    def capacity(self, value: int):
        self.__cli_cap = value

    def connect(self, client):
        if len(self.__clients) < self.__cli_cap:
            self.__clients.append(client)


class Gateway(Switch):

    __protocol: str

    def __init__(self):
        self.reset()
        super().__init__()

    def reset(self):
        self.__protocol = "raw"
        super().reset()

    def __str__(self) -> str:
        return super().__str__() + f'    protocol: {self.__protocol}\n'

    @staticmethod
    def localized_name():
        return "Шлюз"

    @property
    def protocol(self) -> str:
        return self.__protocol
    
    @protocol.setter
    def protocol(self, value: str):
        self.__protocol = value


class Router(Gateway):

    __wps: bool
    __ssid: str
    __passwd: str

    def __init__(self):
        self.reset()
        super().__init__()

    def reset(self):
        self.__wps = False
        self.__ssid = "Default"
        self.__passwd = "admin"
        return super().reset()

    def __str__(self) -> str:
        return (super().__str__() +
                f'    wps mode: {"yes" if self.__wps else "no"}\n'
                f'    SSID: {self.__ssid}\n'
                f'    Password: {"*"*len(self.__passwd)}\n')

    @property
    def ssid(self):
        return self.__ssid
    
    @ssid.setter
    def ssid(self, value: str):
        self.__ssid = value

    @staticmethod
    def localized_name():
        return "Маршрутизатор"

    def is_wps(self) -> bool:
        return self.__wps
    
    def wps_init(self):
        self.__wps = True

    def connect(self, client: Client):
        if client.type == ClientType.WIRED:
            super().connect(client)
        
    def connect(self, client: Client, ssid: str, passwd: str):
        if client.type == ClientType.WIRELESS and ssid == self.__ssid:
            if self.__wps or passwd == self.__passwd:
                super().connect(client)
                self.__wps = False

    def change_passwd(self, old: str, new: str):
        if old == self.__passwd:
            self.__passwd = new


if __name__ == "__main__":
    print("Блять")
