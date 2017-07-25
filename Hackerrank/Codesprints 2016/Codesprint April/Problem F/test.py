lsum = 70
m = 5000
mx = 0
best = (0,0,0)
for i in xrange(1,101):
        for j in xrange(1, 101):
                for k in xrange(1, 101):
                        if mx < i*j*k <= m and i + j + k <= lsum:
                                mx = i*j*k
                                best = (i,j,k)
print best,mx

