from math import sqrt
def dist(a, b):
	return sqrt((a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]))
	
n = input()
l = []
tott = 0
d = 1000000000000

for i in xrange(n):
	x,y = [int(x) for x in raw_input().split()]
	l.append((x,y))

l.sort()

print l

for i in xrange(n):
	for j in xrange(i+1, n):
		tott += 1
		if l[j][0] - l[i][0] >= d:
			break
			
		d = min(d, dist(l[i], l[j]))
		print d

print tott
