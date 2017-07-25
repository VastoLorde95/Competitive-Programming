n, m = [int(x) for x in raw_input().split()]
a = [int(x) for x in raw_input().split()]
b = [int(x) for x in raw_input().split()]
if n > m:
	if (a[0] < 0 and b[0] > 0) or (a[0] > 0 and b[0] < 0):
		print "-Infinity"
	else:
		print "Infinity"
elif n < m:
	print "0/1"
else:
	if (a[0] < 0 and b[0] < 0) or (a[0] > 0 and b[0] > 0):
		a[0] = abs(a[0])
		b[0] = abs(b[0])
		for i in xrange(2,min(a[0],b[0])+1):
			while a[0]%i == 0 and b[0]%i == 0:
				a[0] /= i
				b[0] /= i
		res = str(a[0])+"/"+str(b[0])
		print res
	else:
		a[0] = abs(a[0])
		b[0] = abs(b[0])
		for i in xrange(2,min(a[0],b[0])+1):
			while a[0]%i == 0 and b[0]%i == 0:
				a[0] /= i
				b[0] /= i
		res = "-"+str(a[0])+"/"+str(b[0])
		print res
