file = open("input.txt", "r").readlines()
s = int(file[0])
g = list(map(int, file[1].split()))
g.sort()
print(g)
w = []

while len(g):
    c = g[0]
    g.remove(c)
    if len(g) > 0:
        w.append(g[0]-c)

print(w)

for i in range(len(w)):
    c = w[i+1:]+w[:i]
    print(c, sum(c))
print("fwbeji")

# Умные мюсли

file = open("input.txt", "r").readlines()
s = int(file[0])
g = list(map(int, file[1].split()))
g.sort()

dp = [0]*s
dp[1] = g[1] - g[0]
for i in range(2, s):
    r = g[i] - g[i-1]
    if i == 2:
        dp[i] = dp[i-1] + r
    else:
        dp[i] = min(dp[i-1] + r, dp[i-2] + r)

print(dp[s-1])