number = int(open("input.txt", "r").readline())

if number % 10 != 0:
    print((number - number%10)//5+1)
else:
    print((number - number%10)//5)
    