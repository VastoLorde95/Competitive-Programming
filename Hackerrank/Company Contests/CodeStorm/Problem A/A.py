t = input()

a = 1
b = 2
ans = 0

for i in xrange(1,t+1):
    if i%2 == 0:
        ans += b
        b += 1
    else:
        ans += a
        a += 1
print ans
        

