p = [2,3,5,7,11]
l = []

up = 1
for x in p:
	up *= x

for i in xrange(1, up+1):
	flag = True
	for j in p:
		if i % j == 0:
			flag = False
			break
	if flag:
		l.append(i)

print l
print len(l)
