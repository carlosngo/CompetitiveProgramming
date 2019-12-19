import sys
for line in sys.stdin:
    s = line.split(' ')
    total = 0
    arr = []
    for i in s:
        num = int(i)
        arr.append(num)
        total += num
    for num in arr:
        if total - num == num:
            print(num)
            break

