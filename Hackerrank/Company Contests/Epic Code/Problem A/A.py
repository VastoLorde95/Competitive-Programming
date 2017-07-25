n, p, xx = [int(x) for x in raw_input().split()]
a = [int(x) for x in raw_input().split()]
indx, mx = 0, -1000000000
i = 1
for num in a:
	if p*num > mx:
		mx = p*num
		indx= i
	p -= xx
	i += 1
print indx
