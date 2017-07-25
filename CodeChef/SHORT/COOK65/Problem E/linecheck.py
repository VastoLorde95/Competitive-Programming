file1 = "A.out"
file2 = "B.out"
f1 = open(file1, 'r').read().split()
f2 = open(file2, 'r').read().split()

l = len(f1)
for i in xrange(l):
	if f1[i] != f2[i]:
		print i, f1[i], f2[i]
