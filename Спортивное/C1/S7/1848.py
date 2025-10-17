path = open("input.txt", "r").readline().replace("B", "")

prev = ""
steps = 0
for i in path:
    if i == prev:
        steps += 1
    prev = i

print(steps+1)