import sys
arr = [0] * 42
for i in range(10):
    mod = int(input()) % 42
    arr[mod] = arr[mod] + 1
ans = 0
for i in range(42): 
    if arr[i] > 0:
        ans = ans + 1
print(ans)