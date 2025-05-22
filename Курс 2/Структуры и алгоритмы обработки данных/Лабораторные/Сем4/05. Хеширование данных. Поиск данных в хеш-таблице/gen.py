import sys
from random import uniform

file = open("floats.txt", "w")
count = int(sys.argv[1])

for i in range(count):
    f_value = round(uniform(0.1, 100.9), 6)
    file.write(f"{f_value}\n")
file.close()
