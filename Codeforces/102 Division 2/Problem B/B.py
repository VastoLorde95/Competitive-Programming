s = raw_input().split('.')
if len(s) == 1:
	s.append("00")
else:
	if len(s[1]) == 1:
		s[1] += "0"
	else:
		s[1] = s[1][:2]
tmp = ""
i = 1
while len(s[0])-i >= 0:
	#print tmp, s[0], len(s[0])-i
	if i > 1 and i%3 == 1:
		tmp += ',' + s[0][len(s[0])-i]
	else:
		tmp += s[0][len(s[0])-i]
	i += 1

tmp += '$'

tmp = tmp[::-1]

if '-' in tmp:
	if tmp[2] == ',':
		tmp = tmp[:2] + tmp[3:]
else:
	if tmp[1] == ',':
		tmp = tmp[:1] + tmp[2:]
		
s[0] = tmp

if '-' in s[0]:
	res = '(' + s[0][:1] + s[0][2:] + '.' + s[1] + ')'
	print res
else:
	res = s[0] + '.' + s[1]
	print res
