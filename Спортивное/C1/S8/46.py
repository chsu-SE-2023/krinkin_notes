size = int(open("input.txt", "r").readline())
e_str = "2.7182818284590452353602875"

last = 25-(25-size)+1
if size == 0: e_str = "3"
elif size < 25 and int(e_str[last+1]) >= 5:
    e_str = e_str[:last] + str(int(e_str[last])+1) + e_str[last + 1:]
print(e_str[:size+2])
