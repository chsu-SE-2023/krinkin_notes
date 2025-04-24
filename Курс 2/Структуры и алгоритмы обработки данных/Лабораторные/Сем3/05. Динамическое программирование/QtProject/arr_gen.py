from random import randint
import sys

file = open("input.txt", "w")

n = int(sys.argv[1])
array = [[randint(0, 9) for j in range(n)] for i in range(n)]

file.write(str(n))
file.write('\n')

for i in range(n):
    s = ""
    for j in range(n):
        s += str(array[i][j])+" "
    file.write(s+'\n')

file.close()
