import time

# variant = int(input("1. list и dict\n"
#                     "2. set и defaultdict\n"
#                     "3. dict и deque\n"
#                     "4. defaultdict и heapq\n"
#                     "5. deque и counter\n"
#                     "6. heapq и list\n"
#                     "7. counter и set\n"
#                     "Введите номер задания: "))

test_data = map(int, range(1000000))

# Декоратор, измеряющий скорость выполнения функции
def timer(func):
    def wrapper(*args, **kwargs):
        start_time = time.perf_counter()
        value = func(*args, **kwargs)
        end_time = time.perf_counter()
        print(f"Время выполнения: {(end_time - start_time)*1000:.3f}ms")
        return value
    return wrapper

# Structures:
# list - TODO (mul, sub)
# dict - TODO
# set - TODO
# defaultdict - TODO
# deque - TODO
# heapq - TODO
# counter - TODO

class ListTest:

    t_list = list(test_data)

    @timer
    def access(self):
        value = 0
        for i in range(len(self.t_list)):
            value = self.t_list[i]

    @timer
    def adding(self):
        for i in range(len(self.t_list)):
            self.t_list[i] = self.t_list[i]
    
    @timer
    def removing(self):
        for i in range(len(self.t_list)):
            self.t_list.remove(i)

    @timer
    def concat(self, another: list):
        self.t_list += another

    @timer
    def mul(self, another: list):
        self.t_list *= another

    @timer
    def sub(self, another: list):
        self.t_list -= another

    @timer
    def equal(self, another: list):
        self.t_list == another

    @timer
    def search(self):
        self.t_list.count(-42)

    @timer
    def sort(self):
        self.t_list.sort()

ListTest().sort()