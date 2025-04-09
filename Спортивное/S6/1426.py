size = int(open("../S5/input.txt", "r").readline())

for i in range(size):
    line = "."*size
    line = line[:i] + "*" + line[i + 1:]
    line = line[:size-i-1] + "*" + line[size-i:]
    line = line[:size//2] + "*" + line[size//2+1:]
    if i == size//2:
        line = "*"*size
    print(line)