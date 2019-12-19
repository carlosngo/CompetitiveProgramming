s = input().split(' ')
empty = int(s[0]) + int(s[1])
req = int(s[2])
ans = 0
while empty >= req:
    new = empty // req
    ans += new
    empty = empty % req + new
print(ans)