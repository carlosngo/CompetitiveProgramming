import sys
weekMins = 10080
ans = []
s = input().split(' ')
lawn = int(s[0])
m = int(s[1])
minPrice = sys.float_info.max
for i in range(m):
    s = input().split(',')
    name = s[0]
    price = int(s[1])
    cut = int(s[2])
    time = int(s[3])
    recharge = int(s[4])
    meters = 0
    timer = 0
    while timer < 10080:
        if timer + time >= 10080:
            meters += cut * (10080 - timer - 1)
            break
        meters += cut * time
        timer += time + recharge
    if meters >= lawn: 
        if price < minPrice:
            minPrice = price
            ans = []
            ans.append(name)
        elif price == minPrice:
            ans.append(name)
if len(ans) == 0:
    print("no such mover")
else:
    for i in ans:
        print(i)

        

