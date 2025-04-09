count = int(open("input.txt", "r").readline())
left = 0
right = 32
for time in open("input.txt", "r").readlines()[1:count+1]:
    start, end = map(int, time.strip().split(" "))
    left = max(left, start)
    right = min(right, end)

if left - right <= 0: print("YES")
else: print("NO")