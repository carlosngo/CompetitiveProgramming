t = int(input())
for i in range(t):
    s = input().split(' ')
    n = int(s[0])
    sum = 0.0
    grades = []
    for j in range(1, n + 1):
        grade = float(s[j])
        grades.append(grade)
        sum += grade
    ave = sum / n
    ctr = 0
    for j in range(n):
        if grades[j] > ave:
            ctr = ctr + 1
    print(("%.3f" % round(ctr / n * 100, 3)) + "%")