input = open("input.txt", "r").readlines()
x, y = map(int, input[0].split(" "))
count = 0
for i in range(1, x+1):
    first = input[i].strip()
    second = input[1+x+i].strip()
    for j in range(len(first)):
        if first[j] == second[j]:
            count += 1
print(count)
