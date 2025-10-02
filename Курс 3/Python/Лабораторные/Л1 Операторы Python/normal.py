import math

# Математические выражения в виде анонимных функций
exprs = {
    1: lambda a, b, c, d: (a - b) / (2 & int(c)) * math.log(d, c),
    2: lambda a, b, c, d: int(abs(a)) & 5 - (b + math.log(c) + d) / 2,
    3: lambda a, b, c, d: (int(math.e ** a) | int(b)) / c - d * 5 | int(math.log(d, 2)),
    4: lambda a, b, c, d: ~int(a) + b / (2+c) + (int(d**(1/4)) & 1),
    5: lambda a, b, c, d: (a - int(b) & int(c)) / (d ** (1/3) % 5),
    6: lambda a, b, c, d: int(a) | int((b / (c * d)) - 5 + math.e - math.sin(d)),
    7: lambda a, b, c, d: a - b // c + (3 | int(d)) + 2,
    8: lambda a, b, c, d: (a ** 2 - 4) / (b + c) - ~int(d),
    9: lambda a, b, c, d: ~int(a) - b / (c+d*2) + math.pi,
    10: lambda a, b, c, d: 2 * int((a**(b**c) / (3 * b - c))) & int(math.gcd(int(d), int(c)))
}

# Обёртка для проверки введено ли число
def numeric_input(message):
    symbols = input(message).strip()
    try:
        return float(symbols)
    except ValueError:
        print("Вы ввели не число")
        return None

print(" * Подсказка: для завершения программы введите 0")
while True:
    choice = numeric_input("Введите номер математического выражения (1-10): ")
    if choice == 0: exit()
    a = numeric_input("a = ")
    if not a: continue
    b = numeric_input("b = ")
    if not b: continue
    c = numeric_input("c = ")
    if not c: continue
    d = numeric_input("d = ")
    if not d: continue
    try:
        print(f"Значение выражения: {exprs[int(choice)](a, b, c, d):.3f}")
    except ZeroDivisionError:
        print("Произошло деление на ноль!")