import time

from collections import defaultdict
from collections import deque
from collections import Counter as counter
import heapq

DATA_SIZE = 100000
test_data = list


# Декоратор, измеряющий скорость выполнения функции
def timer(func):
    def wrapper(*args, **kwargs):
        try:
            start_time = time.perf_counter()
            func(*args, **kwargs)
            end_time = time.perf_counter()
            return f"{(end_time - start_time)*1000:.3f}ms"
        except NotImplementedError:
            return "None"
    return wrapper


def test_table(type_1, type_2):
    width = 10
    compare_1 = type_1().get_data()
    compare_2 = type_2().get_data()
    print(f"| Операция    | {type_1().__class__.__name__:<{width}} | {type_2().__class__.__name__:<{width}} |")
    print(f"+-------------+------------+------------+")
    print(f"| Доступ      | {type_1().access():<{width}} | {type_2().access():<{width}} |")
    print(f"| Добавление  | {type_1().adding():<{width}} | {type_2().adding():<{width}} |")
    print(f"| Удаление    | {type_1().removing():<{width}} | {type_2().removing():<{width}} |")
    print(f"| Объединение | {type_1().concat(compare_1):<{width}} | {type_2().concat(compare_2):<{width}} |")
    print(f"| Пересечение | {type_1().mul(compare_1):<{width}} | {type_2().mul(compare_2):<{width}} |")
    print(f"| Разница     | {type_1().sub(compare_1):<{width}} | {type_2().sub(compare_2):<{width}} |")
    print(f"| Сравнение   | {type_1().equal(compare_1):<{width}} | {type_2().equal(compare_2):<{width}} |")
    print(f"| Поиск       | {type_1().search():<{width}} | {type_2().search():<{width}} |")
    print(f"| Сортировка  | {type_1().sort():<{width}} | {type_2().sort():<{width}} |")
    print(f"+-------------+------------+------------+")


class ListTest:

    t_list = list
    test_data = list

    def __init__(self):
        self.test_data = test_data.copy()
        self.t_list = list(self.test_data)

    @timer
    def access(self):
        value = 0
        for i in range(len(self.t_list)):
            value = self.t_list[i]

    @timer
    def adding(self):
        for i in range(DATA_SIZE):
            self.t_list.append(self.test_data[i])
    
    @timer
    def removing(self):
        for i in self.t_list:
            self.t_list.remove(i)

    @timer
    def concat(self, another: list):
        self.t_list += another

    @timer
    def mul(self, another: list):
        raise NotImplementedError() # Тип не поддерживает эту операцию

    @timer
    def sub(self, another: list):
        raise NotImplementedError() # Тип не поддерживает эту операцию

    @timer
    def equal(self, another: list):
        self.t_list == another

    @timer
    def search(self):
        self.t_list.count(-42)

    @timer
    def sort(self):
        self.t_list.sort()

    def get_data(self):
        return self.t_list

class DictTest:

    t_dict = {}
    test_data = list

    def __init__(self):
        self.test_data = test_data.copy()
        for i in self.test_data:
            self.t_dict[str(i)] = i

    @timer
    def access(self):
        value = 0
        for i in range(len(self.t_dict)):
            value = self.t_dict[str(i)]

    @timer
    def adding(self):
        t_len = len(self.t_dict)
        for i in range(DATA_SIZE):
            self.t_dict[str(t_len+i)] = self.test_data[i]
    
    @timer
    def removing(self):
        for i in range(len(self.t_dict)):
            del self.t_dict[str(i)]

    @timer
    def concat(self, another: dict):
        self.t_dict |= another

    @timer
    def mul(self, another: dict):
        raise NotImplementedError() # Тип не поддерживает эту операцию

    @timer
    def sub(self, another: dict):
        raise NotImplementedError() # Тип не поддерживает эту операцию

    @timer
    def equal(self, another: dict):
        self.t_dict == another

    @timer
    def search(self):
        str(-42) in self.t_dict

    @timer
    def sort(self):
        raise NotImplementedError() # Тип не поддерживает эту операцию

    def get_data(self):
        return self.t_dict

class SetTest:

    t_set = set
    test_data = list

    def __init__(self):
        self.test_data = test_data.copy()
        self.t_set = set(self.test_data)

    @timer
    def access(self):
        value = 0
        for i in range(len(self.t_set)):
            value = self.t_set.pop()

    @timer
    def adding(self):
        for i in range(len(self.t_set)):
            self.t_set.add(self.test_data[i])
    
    @timer
    def removing(self):
        for i in range(len(self.t_set)):
            self.t_set.remove(i)

    @timer
    def concat(self, another: set):
        self.t_set |= another

    @timer
    def mul(self, another: set):
        self.t_set &= another

    @timer
    def sub(self, another: set):
        self.t_set -= another

    @timer
    def equal(self, another: set):
        self.t_set == another

    @timer
    def search(self):
        -42 in self.t_set

    @timer
    def sort(self):
        raise NotImplementedError() # Тип не поддерживает эту операцию
    
    def get_data(self):
        return self.t_set

class DefaultDictTest:

    t_dict = defaultdict(int)
    test_data = list

    def __init__(self):
        self.test_data = test_data.copy()
        for i in self.test_data:
            self.t_dict[str(i)] = i

    @timer
    def access(self):
        value = 0
        for i in range(len(self.t_dict)):
            value = self.t_dict[str(i)]

    @timer
    def adding(self):
        t_len = len(self.t_dict)
        for i in range(DATA_SIZE):
            self.t_dict[str(t_len+i)] = self.test_data[i]
    
    @timer
    def removing(self):
        for i in range(len(self.t_dict)):
            del self.t_dict[str(i)]

    @timer
    def concat(self, another: defaultdict):
        self.t_dict |= another

    @timer
    def mul(self, another: defaultdict):
        raise NotImplementedError() # Тип не поддерживает эту операцию

    @timer
    def sub(self, another: defaultdict):
        raise NotImplementedError() # Тип не поддерживает эту операцию

    @timer
    def equal(self, another: defaultdict):
        self.t_dict == another

    @timer
    def search(self):
        str(-42) in self.t_dict

    @timer
    def sort(self):
        raise NotImplementedError() # Тип не поддерживает эту операцию
    
    def get_data(self):
        return self.t_dict
    
class DequeTest:

    t_set = deque
    test_data = list

    def __init__(self):
        self.test_data = test_data.copy()
        self.t_set = deque(self.test_data)

    @timer
    def access(self):
        value = 0
        for i in range(len(self.t_set)):
            value = self.t_set.pop()

    @timer
    def adding(self):
        for i in range(len(self.t_set)):
            self.t_set.append(self.test_data[i])
    
    @timer
    def removing(self):
        for i in range(len(self.t_set)):
            self.t_set.remove(i)

    @timer
    def concat(self, another: deque):
        raise NotImplementedError() # Тип не поддерживает эту операцию

    @timer
    def mul(self, another: deque):
        raise NotImplementedError() # Тип не поддерживает эту операцию

    @timer
    def sub(self, another: deque):
        raise NotImplementedError() # Тип не поддерживает эту операцию

    @timer
    def equal(self, another: deque):
        self.t_set == another

    @timer
    def search(self):
        -42 in self.t_set

    @timer
    def sort(self):
        raise NotImplementedError() # Тип не поддерживает эту операцию
    
    def get_data(self):
        return self.t_set

class HeapQTest:

    t_heapq = heapq
    test_data = list

    def __init__(self):
        self.test_data = test_data.copy()
        self.t_heapq = self.test_data
        heapq.heapify(self.t_heapq)

    @timer
    def access(self):
        value = 0
        for i in range(len(self.t_heapq)):
            value = heapq.heappop(self.t_heapq)

    @timer
    def adding(self):
        for i in range(len(self.t_heapq)):
            heapq.heappush(self.t_heapq, self.test_data[i])
    
    @timer
    def removing(self):
        raise NotImplementedError() # Тип не поддерживает эту операцию

    @timer
    def concat(self, another: heapq):
        heapq.merge(self.t_heapq, another)

    @timer
    def mul(self, another: heapq):
        raise NotImplementedError() # Тип не поддерживает эту операцию

    @timer
    def sub(self, another: heapq):
        raise NotImplementedError() # Тип не поддерживает эту операцию

    @timer
    def equal(self, another: heapq):
        self.t_heapq == another

    @timer
    def search(self):
        -42 in self.t_heapq

    @timer
    def sort(self):
        raise NotImplementedError() # Тип не поддерживает эту операцию

    
    def get_data(self):
        return self.t_heapq
    
class CounterTest:

    t_counter = counter
    test_data = list

    def __init__(self):
        self.test_data = test_data.copy()
        self.t_counter = counter(self.test_data)

    @timer
    def access(self):
        value = 0
        for i in range(len(self.t_counter)):
            value = self.t_counter.pop(i)

    @timer
    def adding(self):
        t_len = len(self.t_counter)
        for i in range(t_len):
            self.t_counter[str(t_len+i)] = self.test_data[i]
    
    @timer
    def removing(self):
        for i in range(len(self.t_counter)):
            self.t_counter.popitem()

    @timer
    def concat(self, another: set):
        self.t_counter |= another

    @timer
    def mul(self, another: set):
        self.t_counter &= another

    @timer
    def sub(self, another: set):
        self.t_counter -= another

    @timer
    def equal(self, another: set):
        self.t_counter == another

    @timer
    def search(self):
        -42 in self.t_counter

    @timer
    def sort(self):
        raise NotImplementedError() # Тип не поддерживает эту операцию
    
    def get_data(self):
        return self.t_counter


if __name__ == "__main__":

    DATA_SIZE = int(input("Введите размер данных: "))
    test_data = list(range(0, DATA_SIZE))

    variant = int(input("1. list и dict\n"
                    "2. set и defaultdict\n"
                    "3. dict и deque\n"
                    "4. defaultdict и heapq\n"
                    "5. deque и counter\n"
                    "6. heapq и list\n"
                    "7. counter и set\n"
                    "Введите номер задания: "))
    
    match variant:
        case 1: test_table(ListTest, DictTest)
        case 2: test_table(SetTest, DefaultDictTest)
        case 3: test_table(DictTest, DequeTest)
        case 4: test_table(DefaultDictTest, HeapQTest)
        case 5: test_table(DequeTest, CounterTest)
        case 6: test_table(HeapQTest, ListTest)
        case 7: test_table(CounterTest, SetTest)
