n = input()
if n == 1:
	print 1
else:
	a = [int(x) for x in raw_input().split()]
	mx = 2
	cnt = 2
	i = 2
	while i < n:
		if a[i] == a[i-1] + a[i-2]:
			cnt += 1
			mx = max(mx, cnt)
		else:
			cnt = 2
		i += 1
	print mx
		
