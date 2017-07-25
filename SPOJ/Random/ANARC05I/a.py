inp = raw_input()
while inp[0] != 'Q':
	x = 0
	y = 0
	count = 0
	i = 0
	a = []
	a.append((x,y))
	while inp[i] != 'Q':
		if inp[i] == 'U':
			y += 1
			if (x,y) in a:
				count += 1
			else:
				a.append((x,y))
		if inp[i] == 'D':
			y -= 1
			if (x,y) in a:
				count += 1
			else:
				a.append((x,y))
		if inp[i] == 'R':
			x += 1
			if (x,y) in a:
				count += 1
			else:
				a.append((x,y))
		if inp[i] == 'L':
			x -= 1
			if (x,y) in a:
				count += 1
			else:
				a.append((x,y))
		i += 1
	print count
	inp = raw_input()

