import sys
t = int(input())
for a in range(t):
    n = int(input())
    ans = 0
    max = sys.float_info.min 
    for i in range(1, n + 1):
        s = input().split(' ')
        a = float(s[0])
        b = float(s[1])
        c = float(s[2])
        x = b / (2 * a)
        torque = -a * x * x + b * x + c
        if torque > max:
            max = torque
            ans = i
    print(ans)

