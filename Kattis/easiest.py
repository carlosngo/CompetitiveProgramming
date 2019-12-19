n = int(input())
while(n != 0):
    found = False
    nSum = 0
    temp = n
    ans = 100
    while (temp > 0):
        nSum += temp % 10
        # print(nSum)
        temp = temp // 10
    for i in range(11, 100):
        prod = n * i
        sum = 0
        temp = prod 
        while (temp > 0):
            sum += temp % 10
            temp = temp // 10
        # print(prod)
        # print(sum)
        if sum == nSum:
            ans = i
            break
    print(ans)
    n = int(input())