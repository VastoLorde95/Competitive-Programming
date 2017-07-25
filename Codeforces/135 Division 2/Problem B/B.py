p, d = [int(x) for x in raw_input().split()]
p = str(p)
l = len(str(p))
cnt = 0
sub = 0
for i in xrange(1,l+1):
	n = (10**i) - 1
	m = int(p[l-i:l])
	if m == n:
		sub = 0
	elif m+1 <= d:
		sub = m+1
	else:
		break
	
print int(p) - sub	
