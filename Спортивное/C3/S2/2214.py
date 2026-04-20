b = input()
l = len(b)//2
sum1 = sum(map(int, b[:l]))
sum2 = sum(map(int, b[l:]))
res1 = int(b[:l])
res2 = int(b[l:])
if (sum1 == sum2):
    res2 += 1
    sum2 += 1

while (sum(map(int, str(res1))) != sum(map(int, str(res2)))):
    if (res2//(10**(len(str(res2))-1)) >= sum1):
        res1 += 1
        sum1 += 1
        res2 = 0
        sum2 = 0
    
    if (sum2 < sum1):
        res2 += sum1 - sum2
    
    if (sum2 > sum1):
        res2 += 10-res2%10
        res2 += sum1-(res2//10)
 
print(f"{res1:0{l}}{res2:0{l}}")

# 5501
# 5519

# 5555
# 5629
