s = input().split(' ')
a = int(s[0])
b = int(s[1])
c = int(s[2])
if (a + b == c):
    print(s[0] + "+" + s[1] +  "=" + s[2])
elif (a - b == c):
    print(s[0] + "-" + s[1] +  "=" + s[2])
elif (a * b == c):
    print(s[0] + "*" + s[1] +  "=" + s[2])
elif (a / b == c):
    print(s[0] + "/" + s[1] +  "=" + s[2])
elif (b + c == a):
    print(s[0] + "=" + s[1] +  "+" + s[2])
elif (b - c == a):
    print(s[0] + "=" + s[1] +  "-" + s[2])
elif (b * c == a):
    print(s[0] + "=" + s[1] +  "*" + s[2])
elif (b / c == a):
    print(s[0] + "=" + s[1] +  "/" + s[2])