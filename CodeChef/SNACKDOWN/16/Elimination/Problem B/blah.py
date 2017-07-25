a = open('A.out', 'rw+').read().split()
b = open('B.out', 'rw+').read().split()
l = len(a)
for i in xrange(l):
    if a[i] != b[i]:
             print i+1
             break
