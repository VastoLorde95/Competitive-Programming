n = input()
a = [int(x) for x in raw_input().split()]
b = [int(x) for x in raw_input().split()]
l = []
for i in xrange(n):
	l.append((a[i],b[i]))
	
mx = 1
