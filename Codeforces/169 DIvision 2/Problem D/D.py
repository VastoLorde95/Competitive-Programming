a, b = [int(x) for x in raw_input().split()]
if a > b:
	swap(a,b)
if True:
	#all hell has broken lose
	num = a	
	temp = 0
	i = 0
	mx = 0
	while (1<<i) <= b:
		if (num&(1<<i)) == 0:
			temp = num | (1<<i)
		else:
			temp = num
			num ^= (1<<i)
		if a <= temp <= b:
			if temp-1 >= a:
				mx = max(mx, temp^(temp-1))
		i += 1
	print mx
