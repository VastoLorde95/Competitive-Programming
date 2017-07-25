n = input()
s = raw_input().lower()
d = {}
for c in s:
	d[c] = 1
if len(d) == 26:
	print "YES"
else:
	print "NO"

