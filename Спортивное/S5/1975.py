file = open("input.txt", "r").readlines()
first = file[0].split(":")
second = file[1].split(":")
hour = str((24-int(first[0])+int(second[0]))%24)
minutes = str((60-int(first[1])+int(second[1]))%60)
hour = "0"+hour if len(hour) < 2 else hour
minutes = "0"+minutes if len(minutes) < 2 else minutes
print(hour+":"+minutes)