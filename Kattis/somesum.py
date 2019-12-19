n = int(input())
odd = False
even = False
for i in range (1, 101):
    sum = 0
    for j in range (i, i + n):
        sum += j
    if sum % 2 == 0:
        even = True
    else:
        odd = True

if even == True and odd == True:
    print('Either')
elif odd == True:
    print('Odd')
else:
    print('Even')