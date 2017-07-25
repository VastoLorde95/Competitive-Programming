n, K = [int(x) for x in raw_input().split()]
a = [int(x) for x in raw_input().split()]
ans = 0
for i in xrange(n):
	for j in xrange(i,n):
		cnt = 0
		for k in xrange(i,j+1):
			for l in xrange(k+1,j+1):
				if a[k] > a[l]:
					cnt += 1
		if cnt >= K:
			ans += 1
print ans			
