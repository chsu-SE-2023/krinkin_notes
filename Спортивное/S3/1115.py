n, k = map(int, open("input.txt", "r").readline().split(" "))

base = (k-(k%n))
one = base//n
two = k-base
three = n - k%n if k%n else 0

print(one, two, three)