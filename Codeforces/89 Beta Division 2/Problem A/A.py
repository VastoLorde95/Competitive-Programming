d = {"A","E","I","O","U","Y"}
s = raw_input()
res = ""
for c in s:
	if c.upper() not in d:
		res += '.'
		res += c.lower()
print res
