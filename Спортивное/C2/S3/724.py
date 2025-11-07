file = open("input.txt", "r")
n, m = map(int, file.readline().split())
arr = [list(map(int, x.split(" "))) for x in file.readlines()]
zeros = dict()
for i in range(n):
    zeros[f"{i}"] = 0

lines = []
for j in range(m):
    lines.append([int(arr[i][j]) for i in range(n)])
for line in lines:
    for x in range(len(line)):
        if line[x] == 0:
            zeros[str(x)] += 1

if 0 in zeros.values():
    print("Impossible")
    exit()

l = []
index = []
for x in range(len(zeros)):
    for i in range(len(lines)):
        if lines[i][x] == 0 and lines[i] not in l:
            l.append(lines[i])
            index.append(i+1)
            break
index.sort()

print(len(index))
print(" ".join(map(str, index)))
