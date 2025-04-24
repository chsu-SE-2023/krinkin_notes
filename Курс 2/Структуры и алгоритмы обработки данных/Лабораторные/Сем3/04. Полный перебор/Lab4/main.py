file = open("file.txt", "r").readlines()
output = open("output.txt", "w")
file[0] = file[0].strip()
file[1] = file[1].strip()

founded = False
for i in range(1 << len(file[0])):
    bin_str = f"{i:0{len(file[0])}b}"
    indexes = [ i for i in range(len(bin_str)) if bin_str[i] == "1" ]

    new_str = file[0]
    for j in range(len(indexes)):
        new_str = new_str[:indexes[j]-j] + new_str[indexes[j]-j+1:]

    if new_str == file[1]:
        output.write(str(indexes)+"\n")
        founded = True

if not founded: output.write("Not possible!")
output.close()