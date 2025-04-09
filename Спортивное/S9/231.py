d=""
m=0
for c in input().strip():
    if 47<ord(c)<58: m=m*10+int(c)
    else:
        if m==0: m=1
        d+=c*m
        m=0
for i in range(len(d)//40+1):
    print(d[40*i:40*(i+1)])
