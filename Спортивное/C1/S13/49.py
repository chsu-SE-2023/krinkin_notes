pattern = {
    'a': [0, 1, 2, 3],
    'b': [1, 2, 3, 4],
    'c': [2, 3, 4, 5],
    'd': [3, 4, 5, 6],
    'e': [4, 5, 6, 7],
    'f': [5, 6, 7, 8],
    'g': [6, 7, 8, 9],
    '?': [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
}
file = open('input.txt', 'r').readlines()

count = 1

for i in range(len(file[0]) - 1):
    match = 0

    arr1 = [int(file[0][i])] if file[0][i].isnumeric() else pattern[file[0][i]]
    arr2 = [int(file[1][i])] if file[1][i].isnumeric() else pattern[file[1][i]]

    for j in arr1:
        for k in arr2:
            if j == k:
                match += 1
    count *= match

print(count)
