s = "CODEFORCES"
t = raw_input()
n = len(t)
flag = 0
for i in xrange(n):
	for j in xrange(n):
		tmp = t[:i] + t[j+1:]
		if tmp == s:
			flag = 1
if flag == 1:
	print "YES"
else:
	print "NO"
				
