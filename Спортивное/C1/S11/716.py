input = open("input.txt", "r").readlines()
k = int(input[0])
closer = []
further = []
for i in range(1, k+1):
    if input[i].count("closer"):
        closer.append(float(input[i].replace(" closer", "")))
    if input[i].count("further"):
        further.append(float(input[i].replace(" further", "")))
if len(closer) > 1: first = (min(closer)+max(closer))/2
else: first = 30.0
if len(further) != 0 and len(closer) != 0: second = (max(further)+min(closer))/2
else: second = 4000.0
print(min(first, second), max(first, second))