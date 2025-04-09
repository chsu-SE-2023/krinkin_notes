import math
index = int(open("input.txt", "r").readline())
if index % 2 == 0:
    print(math.ceil(((index - 1) * 6 + 1)/2)+1)
else:
    print(math.ceil(((index - 1) * 6 + 1)/2))