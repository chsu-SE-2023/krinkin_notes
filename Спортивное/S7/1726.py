n, m, t = map(int, open("input.txt", "r").readlines())

for j in range(n*m):
    need = 0
    for i in range(j):
        need += (n-i)*2 + ((m-i)-2*(i+1))*2
    if need > t or need < 0:
        print(j-1)
        break