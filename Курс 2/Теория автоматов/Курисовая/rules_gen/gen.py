import csv

prev = "none"

with open('switch_rules.csv', mode ='r')as file:
    rules = csv.reader(file)
    for lines in rules:
        s = lines[0]
        ch = lines[1] if lines[1] != "default" else "Ɐ"
        des = lines[2]

        if des == "0" and ch == "Ɐ":
            continue
        if s == prev:
            print(f" | {ch}S{des}", end="")
        else:
            print(f"\nS{s} → {ch}S{des}", end="")
        prev = lines[0]
