dp = []
dp2 = []
t = input()
for i in xrange(1000):
	dp.append([])
	dp2.append([])
dp[0] = [1]*1000
dp2[0] = range(1,1000)
for i in xrange(1,1000):
	dp[0].append(1)
	dp[i].append(1)
	dp2[0].append(i+1)
	dp2[i].append(i+1)
for i in xrange(1,1000):
	for j in xrange(1,1000):
		dp[i].append(dp[i-1][j] + dp[i][j-1])
		dp2[i].append(dp2[i][j-1]  + dp[i][j])
for i in xrange(10):
	for j in xrange(10):
		print dp2[i][j],'\t',
	print
for t in xrange(t):
	n, m = [int(x) for x in raw_input().split()]
	res = 0
	for i in xrange(n):
		res += dp2[i][m-1]
	res /= (dp[n-1][m-1]*1.0)
	print res
	
