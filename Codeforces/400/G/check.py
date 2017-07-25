l = [67]
for p in l:
	v = ((1 << p)+1)/3
	j = 3
	while j * j <= v:
		if v % j == 0:
			if (j-1) % p != 0:
				print p, j
			if ((v/j)-1) %  p != 0:
				print p, j
		j += 2		
