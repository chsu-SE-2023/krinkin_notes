line = open('input.txt', 'r').readline()
count = 0

current = 0
while line.find('<--<<', current) != -1:
    current = line.find('<--<<', current) + 4
    count += 1
current = 0
while line.find('>>-->', current) != -1:
    current = line.find('>>-->', current) + 4
    count += 1

print(count)