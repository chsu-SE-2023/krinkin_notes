import math
n, m, k = map(int, open("input.txt", "r").readline().split(" "))
print(math.ceil(abs(n - m) / k) + math.ceil((min(n, m) - 1) / k))
