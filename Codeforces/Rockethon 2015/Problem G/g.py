n, k = [int(x) for x in raw_input().split()]
p = [int(x) for x in raw_input().split()]
di = {}
def recur(l, d):
	if d == k:
		inv2 = 0
		#print l
		for i in xrange(n):
			for j in xrange(i+1, n):
				if l[i] > l[j]:
					inv2 += 1
		if inv2 in di:
			di[inv2] += 1
		else:
			di[inv2] = 1
		return
	for i in xrange(0, n+1):
		for j in xrange(n-i):
			temp = []
			for i in l:
				temp.append(i)
			#print temp[j:j+i][::-1]
			x = temp[j:j+i]
			#print x, i, j
			temp = temp[:j] + x[::-1]  + temp[j+i:]
			#print temp, i
			recur(temp, d+1)

recur(p, 0)
count = 0
s = 0
for i in di:
	s += di[i]*i
	count += di[i]
print s/(count*1.0) - 1
