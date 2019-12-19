def calcAnB(arr, n):
    for a in range(10001):
        for b in range(10001):
            valid = True
            for k in range(2, 2 * n, 2):
                arr[k] = (a * arr[k - 1] + b) % 10001
                if arr[k + 1] != (a * arr[k] + b) % 10001:
                    valid = False
                    break
            if valid == True:
                return a,b
n = int(input())
arr = [None] * (2 * n + 1)
for i in range(1, 2 * n + 1, 2):
    num = int(input())
    arr[i] = num
a, b = calcAnB(arr, n)
arr[2 * n] = (a * arr[2 * n - 1] + b) % 10001
for k in range(2, 2 * n + 1, 2):
    print(arr[k])

                

