s = input().split(' ')
n = int(s[0])
p = int(s[1]) / 100
k = int(s[2])
s = input().split(' ')
time = 0.0
speed = 1.0
prev = 0
ans = 0
stamps = []
stamps.append(0)
for i in range(n):
    stamp = int(s[i])
    stamps.append(stamp)    
stamps.append(k)

for i in range(1, n + 2):
    stamp = stamps[i]
    ans += (stamp - prev) * speed
    speed += p
    prev = stamp
print("%.6f" % ans)


