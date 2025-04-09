num = open("input.txt", "r").readline().strip()
print("YES") if num[:len(num)//2] == num[len(num)//2:][::-1] else print("NO")
