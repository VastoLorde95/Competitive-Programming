n = input()
a = [int(x) for x in raw_input().split()]
s = sum(a)
d = {}
for i in a:
	if i in d:
		 d[i] += 1
	else:
		d[i] = 1
if s%3 == 0 and 0 in d and d[0] != n:
	a.sort(reverse=True)
	res = ""
	for i in a:
		res += str(i)
	print res
else:
	rem = s%3
	if rem == 1:
		if 1 in d:
			d[1] -= 1
			rem = 0
		elif 4 in d:
			d[4] -= 1
			rem = 0
		elif 7 in d:
			d[7] -= 1
			rem = 0
		elif 2 in d and d[2] >= 2:
			d[2] -= 2
			rem = 0
		elif 2 in d and 5 in d and d[2] > 0 and d[5] > 0:
			d[2] -= 1
			d[5] -= 1
			rem = 0
		elif 5 in d and d[5] >= 2:
			d[5] -= 2
			rem = 0
		elif 2 in d and 8 in d and d[2] > 0 and d[8] > 0:
			d[2] -= 1
			d[8] -= 1
			rem = 0
		elif 8 in d and d[8] >= 2:
			d[8] -= 2
			rem = 0
		elif 8 in d and 5 in d and d[8] > 0 and d[5] > 0:
			d[8] -= 1
			d[5] -= 1
			rem = 0
	elif rem == 2:
		if 2 in d:
			d[2] -= 1
			rem = 0
		elif 5 in d:
			d[5] -= 1
			rem = 0
		elif 8 in d:
			d[8] -= 1
			rem = 0
		elif 1 in d and d[1] >= 2:
			d[1] -= 2
			rem = 0
		elif 1 in d and 4 in d and d[1] > 0 and d[4] > 0:
			d[1] -= 1
			d[4] -= 1
			rem = 0
		elif 4 in d and d[4] >= 2:
			d[4] -= 2
			rem = 0
		elif 1 in d and 7 in d and d[1] > 0 and d[7] > 0:
			d[1] -= 1
			d[7] -= 1
			rem = 0
		elif 7 in d and d[7] >= 2:
			d[7] -= 2
			rem = 0
		elif 7 in d and 4 in d and d[7] > 0 and d[4] > 0:
			d[7] -= 1
			d[4] -= 1
			rem = 0
	
	if rem != 0 or 0 not in d:
		print -1
	else:
		l = []
		
		for key in d:
			while d[key] > 0:
				l.append(key)
				d[key] -= 1
		
		l.sort(reverse=True)
		
		res = ""
		
		for i in l:
			res += str(i)
		
		if res.count('0') == len(l) or res == "":
			res = "0"
		
		print res
