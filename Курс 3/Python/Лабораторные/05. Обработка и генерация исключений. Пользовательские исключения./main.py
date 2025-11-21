from getpass import getpass

class SameValueException(ValueError):

    def __init__(self, message):
        self.message = message
        super().__init__(message)

class WLAN:

    __ssid: str
    __passwd: str

    def __init__(self, ssid, passwd):
        self.__ssid = ssid
        self.__passwd = passwd

    @property
    def ssid(self):
        return self.__ssid
    
    @ssid.setter
    def ssid(self, ssid: str):
        if not self.__ssid == ssid:
            self.__ssid = ssid
        else:
            raise SameValueException("Попытка смены SSID на такое же")

    def connect(self, passwd: str):
        assert self.__passwd == passwd
        print("Подключение успешно!")

if __name__ == "__main__":
    networks = {
        "SomeNet": WLAN("SomeNet", "12345678"),
        "Default": WLAN("SomeNet", "00000000"),
        "Admin": WLAN("SomeNet", "00000000"),
    }

    while True:

        print("Что вы хотите сделать?")
        try:
            choise = int(input("1. Переименовать сети\n2. Подключиться\n3. Выйти\nВариант: "))
        except ValueError:
            print("Введите число!", "\n")

        if choise == 3: exit()

        print("Список доступных сетей:")
        for net in networks:
            print(f" * {net}")
        ssid = input("Введите имя сети: ").strip()

        if choise == 1:
            
            ssid_new = input("Введите новое имя сети: ").strip()
            
            try:
                networks[ssid].ssid = ssid_new
                networks[ssid_new] = networks[ssid]
                del networks[ssid]
                print("Успешно!")

            except KeyError:
                print("Ошибка! Сеть не найдена!")

            except SameValueException as e:
                print("[Ошибка]", e.message)

            finally:
                print()

        elif choise == 2:
            passwd = getpass("Введите пароль (невидим): ").strip()
            connected = False

            try:
                networks[ssid].connect(passwd)

            except KeyError:
                print("Ошибка! Сеть не найдена!")

            except AssertionError:
                attempts = 1
                print("Введён неверный пароль повторите попыку!")
                while attempts < 3:
                    passwd = getpass("Введите пароль (невидим): ").strip()
                    try:
                        attempts += 1
                        networks[ssid].connect(passwd)
                    except AssertionError:
                        print("Введён неверный пароль повторите попыку!")
                print("Введено 3 неправильных пароля!")

            finally:
                print("[Статус] ", end="")
                print("Подключено!") if connected else print("Не подключено!")
                print() if not connected else exit()
                