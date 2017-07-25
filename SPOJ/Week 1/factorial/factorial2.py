from math import factorial
n = input()
i = 0
l = []
while i<n:
    l.append(input())
    i += 1
for number in l:
    x = factorial(number)
    print x
