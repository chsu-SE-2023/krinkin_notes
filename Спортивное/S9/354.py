from math import sqrt
num = int(open("input.txt", "r").readline())
i = 2
while i <= sqrt(num):
    if num % i == 0:
        print(i, end='')
        num //= i
        if num > 1: print('*', end='')
    else: i = i + 1
if num > 1: print(num)