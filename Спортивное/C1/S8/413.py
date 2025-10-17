from itertools import groupby
file = open("input.txt", "r").readlines()
y, x = map(int, file[0].split())

sizes = {}
for i in range(1, y+1):
    j = [sum(1 for _ in group) for char, group in groupby(file[i][:x]) if char == "#"]
    for c in j:
        if c != 0:
            if str(c) not in sizes:
                sizes[str(c)] = 0
            sizes[str(c)] += 1

count = 0
print(sizes)
for i in sizes:
    count += sizes[i] // int(i)
print(count)