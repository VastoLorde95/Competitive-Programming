n = input()
mask = 0
l = []
for i in xrange(12):
	mask = 0
	while mask < (1<<i):
		num = ""
		for j in xrange(i):
			if (mask&(1<<j)) > 0:
				num = "4" + num
			else:
				num = "7" + num
		if num.count('4') == num.count('7') and num != "":
			l.append(int(num))
		mask += 1
l.sort()
#print l
i = 0
while i < len(l) and l[i] < n:
	i += 1
print l[i]
