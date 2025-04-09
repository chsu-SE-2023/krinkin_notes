file = open("input.txt", "r")
gods = int(file.readline().strip())
names = {}
n = []
for _ in range(gods):
    name = file.readline().strip()
    names[name] = 0
    n.append(name)
sus = int(file.readline().strip())
suses = []
for _ in range(sus):
    suses.append(file.readline().strip())

for g_name in names:
    for sus in suses:
        if len(g_name) != len(sus):
            continue
        if sum(c1 != c2 for c1, c2 in zip(g_name, sus)) == 1:
            names[g_name] += 1

for i in n:
    print(names[i], end = " ")
