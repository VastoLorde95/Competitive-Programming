n, m = [int(x) for x in raw_input().split()]
a = [int(x) for x in raw_input().split()]
a.sort()
res = 1000000
for j in xrange(n-1, m):
	res = min(res, a[j]-a[j-n+1])
print res
