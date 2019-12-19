import sys
l = int(input())
d = int(input())
k = int(input())
n = sys.maxsize
m = -sys.maxsize
for i in range(l, d + 1):
    temp = i
    sum = 0
    while temp > 0:
        sum += temp % 10
        temp = temp // 10
    if sum == k:
        n = min([n, i])
        m = max([n, i])
print(n)
print(m)