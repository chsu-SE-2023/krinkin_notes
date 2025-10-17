from queue import Queue
start, year = map(int, open("input.txt", "r").readline().split())
count = start
q_year = Queue()
q_year.put(start)

for i in range(2, year+1):
    if i % 4 == 0: count -= q_year.get()
    y_count = 0
    if start > 2:
        while start != 0:
            if start % 3 == 0:
                start -= 3
                y_count += 5
            elif start % 5 == 0:
                start -= 5
                y_count += 9
            else:
                start += 3
                y_count -= 5

    q_year.put(y_count)
    count += y_count
    start = count

print(count)