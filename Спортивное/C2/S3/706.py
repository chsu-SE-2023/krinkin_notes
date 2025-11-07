r, x, y = map(int, open("input.txt", "r").readline().split(" "))
print(f'{abs((r*x)/(2*r-y)):.2f}')