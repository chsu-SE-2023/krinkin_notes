from queue import Queue
start, year = map(int, open("input.txt", "r").readline().split())
count = start
q_year = Queue()
q_year.put(start)

for i in range(2, year+1):
    if i % 3 == 0: count -= q_year.get()
    y_count = 0
    while start != 0:
        if start >= 5:
            start -= 5
            y_count += 9
        elif start >= 3:
            start -= 3
            y_count += 5
        else:
            y_count -= 4
            start += 2

    q_year.put(y_count)
    count += y_count
    start = count

print(count)