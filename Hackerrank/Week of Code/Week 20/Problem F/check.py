file1 = "A.out"
file2 = "B.out"
a = open(file1, 'rw+').read().split('\n')
b = open(file2, 'rw+').read().split('\n')

l = len(a)
for i in xrange(l):
	if a[i].strip() != b[i].strip():
		print i
		break
