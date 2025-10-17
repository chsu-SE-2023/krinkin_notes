start, end = map(int, open("input.txt", "r").readlines())
count = 0
prost = [2, 3, 5, 7]

for i in range(len(str(end)) + 1):
    for j in range(i):
        temp = "1" * i
        for p in prost:
            if start <= int(temp[:j] + str(p) + temp[j + 1:]) <= end:
                count += 1

print(count)
