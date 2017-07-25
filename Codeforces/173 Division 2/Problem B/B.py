n = input()
s = 0
for i in xrange(n):
	a, b = [int(x) for x in raw_input().split()]
	s += b
res = ""
while abs(s) > 500:
	s -= 1000
	res += 'A'
if abs(s) > 500:
	print -1
else:
	for i in xrange(n-len(res)):
		res += 'G'
print res
