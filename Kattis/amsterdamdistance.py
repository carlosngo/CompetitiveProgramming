import math
s = input().split(' ')
m = int(s[0])
n = int(s[1])
r = float(s[2])
s = input().split(' ')
ax = int(s[0])
ay = int(s[1])
bx = int(s[2])
by = int(s[3])
fx = [[0,1], [0,-1], [1,0], [-1,0]]

angle = 180 / m
smallR = r / n
arcLen = [None] * (n + 1)
arcLen[0] = 0
for i in range(1, n + 1):
    arcLen[i] = 2 * math.pi * (i) * smallR * (angle / 360)

adjList = [[] for i in range((m + 1) * (n + 1))]
for i in range(m + 1):
    for j in range(n + 1):
        

minY = min([ay, by])
dx = abs(ax - bx)
dy = abs(ay - by)
ans = dy * smallR + dx * arcLen[minY]
print(ans)
