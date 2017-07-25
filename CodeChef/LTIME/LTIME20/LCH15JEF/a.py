def exp(a, b, m):
	ans = 1%m
	while b > 0:
		if b&1:
			ans = (ans*a)%m
		a = (a*a)%m
		b >>= 1
	return ans
def solve(res, s, m, i):
	l = len(s)
	while i < l:
		if i < l-1:
			if s[i] == '*' and s[i+1] == '*':
				i += 2
				b = ""
				while i < l and s[i] != '*':
					b += s[i]
					i += 1
				b = int(b)
				res = exp(res, b, m)
			else:
				i += 1
				b = ""
				while i < l and s[i] != '*':
						b += s[i]
						i += 1
				b = int(b)
				res = (res * solve(b, s, m, i))%m
				break
		else:
			i += 1
			b = ""
			while i < l and s[i] != '*':
					b += s[i]
					i += 1
			b = int(b)
			res = (res * solve(b, s, m, i))%m
			break
	return res
t = input()
for _ in xrange(t):
	li = raw_input().split()
	m = int(li[0])
	s = li[1].strip()
	if m < 10000:
		print eval(s)%m
		continue
	a  = ""
	m = int(m)
	i = 0
	while s[i] != '*':
		a += s[i]
		i += 1
	res = int(a)
	print solve(res, s, m, i)
