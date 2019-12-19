n = int(input())
found = False
while (found == False):
    sum = 0
    temp = n
    while (temp > 0):
        sum = sum + (temp % 10)
        temp = temp // 10
    if n % sum == 0:
        print(n)
        found = True
    n = n + 1