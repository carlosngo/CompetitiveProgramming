s = input().split(' ')
b = int(s[0])
k = int(s[1])
g = int(s[2])
bridgesPerDay = k // g
print(b // bridgesPerDay)
