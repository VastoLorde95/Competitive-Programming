a, b, c, d = [int(x) for x in raw_input().split()]
if 1 >= (a*d - b*c)/(1.0*a*d) >= 0:
	x = a*d - b*c
	y = a*d
	i = 2
	while i <= max(x,y):
		while x > 1 and y > 1 and x%i == 0 and y%i == 0:
			x /= i
			y /= i
		i += 1
	if x == 0: y = 1
	s = str(x)+'/'+str(y)
	print s
elif 1 >= (b*c - a*d)/(1.0*b*c) >= 0:
	x = b*c - a*d
	y = b*c
	i = 2
	while i <= max(x, y):
		while x > 1 and y > 1 and x%i == 0 and y%i == 0:
			x /= i
			y /= i
		i += 1
	if x == 0: y = 1
	s = str(x)+'/'+str(y)
	print s
