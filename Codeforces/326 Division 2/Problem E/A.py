f1 = open('A.out','rw+')
f2 = open('B.out','rw+')
f1 = f1.read().split('\n')
f2 = f2.read().split('\n')
print len(f1) == len(f2)
for i in xrange(len(f1)):
	if f1[i] != f2[i]:
		print i
