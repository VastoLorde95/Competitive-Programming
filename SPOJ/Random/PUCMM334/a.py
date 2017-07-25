n = input()
d = {}
hats = [int(x) for x in raw_input().split()]
count = 0
for hat in hats:
	if hat not in d:
		d[hat] = 1
	else:
		d[hat] += 1
if len(d) > 2:
	print -1
elif len(d) == 1:
	for white in d:
		if white == 0 and d[white] == n:
			print 0
		elif d[white] == white+1 and white+1 == n:
			print n
		else:
			print -1
else:
	l = []
	for hat in d:
		l.append(hat)
	a = min(l)
	b = max(l)
	if d[a] == a+1 and d[b] + d[a] == n and b == a+1:
		print a+1
	else:
		print -1
		
			

