s = raw_input().split('+')
s.sort()
res = s[0]
for i in xrange(1,len(s)):
	res += '+'+s[i]
print res
