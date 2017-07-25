def base(t, b):
	num = 0
	p = 1
	i = len(t)-1
	v = 0
	while i >= 0:
	
		if(t[i].isdigit()):
			v = int(t[i])
		else:
			v = (ord(t[i])-55	)
			
		#print t[i], v
	
		if v >= b:
			return -1
		num += v*p
		p *= b
		
		i -= 1
	return num

def remove_zeroes(t):
	res = ""
	i = 0
	while i < len(t) and t[i] == "0":
		i += 1
	while i < len(t):
		res += t[i]
		i += 1
	if res == "":
		res = "0"
	return res
s = raw_input().split(":")

num = []

for i in xrange(2):
	s[i] = remove_zeroes(s[i])

for i in xrange(2, 61	):
	a = base(s[0],i)
	b = base(s[1],i)
	
	#print a, b, i
	
	if a >= 0 and a <= 23 and b >= 0 and b <= 59:
		num.append(i)
		
#print num

if len(num) == 0:
	print 0
elif 60 in num:
	print -1
else:
	for x in num:
		print x,
