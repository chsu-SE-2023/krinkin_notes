a, b, c = map(int, open("input.txt", "r").readlines())
mi = min(a+b, b+c, c+a)
ma = max(a, b, c)
print(mi - ma)