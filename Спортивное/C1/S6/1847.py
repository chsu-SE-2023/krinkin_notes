file = open("../S7/input.txt", "r")
n, k = map(int, file.readline().split())
times = file.readline().split()
heh = []

for i in times:
    sum_ = 0
    for j in range(n):
        sum_ += ((int(i) % k) + int(times[j]))%k
    heh.append(sum_)

print(int(times[heh.index(min(heh))])%k, end=" ")
heh.remove(min(heh))
times.remove(times[heh.index(min(heh))])
print(int(times[heh.index(min(heh))])%k)