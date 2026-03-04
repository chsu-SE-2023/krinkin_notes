file = open("input.txt", "r")
n = int(file.readline())
stud = list(map(int, file.readline().split(" ")))
stud.sort()
diff = 0
v = 0

for i in range(n):
    if i == 0: continue
    diff = diff+(stud[i]-stud[i-1])*i
    v += diff
    print()
print(v)