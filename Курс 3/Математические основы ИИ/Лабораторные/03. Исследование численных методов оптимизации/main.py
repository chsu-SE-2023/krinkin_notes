import sympy
import math

X1, X2 = sympy.symbols('x1 x2')

examples = [
    X1**3 - X1*X2 + X2**2 - 2*X1 + 3*X2 - 4, # Тестирование 1
    (X2-X1**2)**2 + (1-X1)**2, # Тестирование 2
    (X2**2+X1**2-1)**2+(X1+X2-1)**2, # Задача 1
    (X1**2+X2-11)**2+(X1+X2**2-7)**2, # Задача 2
    4*(X1-5)**2 + (X2-6)**2, # Задача 3, 4, 5
]


def norm(vec: tuple) -> float:
    return math.sqrt(vec[0]**2 + vec[1]**2)


def f(func, x1, x2) -> float:
    l = sympy.lambdify((X1, X2), func, "math")
    return l(x1, x2)


def gradient(func, point: tuple) -> tuple: # Шаг 1. Нахождение градиента
    pr_x = sympy.lambdify((X1, X2), sympy.diff(func, X1), "math")
    pr_y = sympy.lambdify((X1, X2), sympy.diff(func, X2), "math")
    return (pr_x(point[0], point[1]), pr_y(point[0], point[1]))


def descent(func, x_k, e1, e2, m, t):
    # Шаг 2. Объявление k
    k = 0

    # Шаг 5. Проверка выполнения неравенства k >= M
    while k < m:

        # Шаг 3. Вычисление градиента для x_k
        grad = gradient(func, x_k)

        # Шаг 4. Проверка выполнения критерия окончания
        if norm(grad) < e1:
            break

        # Шаг 7.
        x_k1 = (x_k[0] - t * grad[0], x_k[1] - t * grad[1])

        # Шаг 8. Проверка условий
        if norm((x_k[0] - x_k1[0], x_k[1] - x_k1[1])) < e2 and abs(f(func, x_k1[0], x_k1[1]) - f(func, x_k[0], x_k[1])) < e2:
            x_k = x_k1
            break

        # Шаг 8(б).
        x_k = x_k1
        k += 1

    return x_k, k


if __name__ == "__main__":
    for i in range(len(examples)):
        print(f"{i+1}. {examples[i]}")
    p_n = int(input("Введите номер примера: "))

    x_0 = tuple(map(float, input("Положение начальной точки: ").split()))
    eps1 = float(input("Величина параметра e1: "))
    eps2 = float(input("Величина параметра e2: "))
    m = int(input("Предельное количество итераций (M): "))
    t = float(input("Точность (t): "))

    result, iter = descent(examples[p_n-1], x_0, eps1, eps2, m, t)

    print(f"\nРезультат {result} найден на {iter}-ой итерации")
    print(f"f(x1, x2) -> min: {f(examples[p_n-1], result[0], result[1])}")
