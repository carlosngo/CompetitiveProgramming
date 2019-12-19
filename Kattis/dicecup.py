s = input().split(' ')
n = int(s[0])
m = int(s[1])
rolls = [0] * (n + m + 1)
for i in range(1, n + 1):
    for j in range(1, m + 1):
        rolls[i + j] = rolls[i + j] + 1
ans = [1]
max = rolls[1]
for i in range (2, n + m + 1):
    if rolls[i] > max:
        max = rolls[i]
        ans = [i]
    elif rolls[i] == max:
        ans.append(i)
for i in ans:
    print(i)