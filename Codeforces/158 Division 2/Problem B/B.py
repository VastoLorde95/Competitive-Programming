d = {"01":"31","02":"28","03":"31","04":"30","05":"31","06":"30","07":"31","08":"31","09":"30","10":"31","11":"30","12":"31"}
y = {"2013":1,"2014":1,"2015":1}
d2 = {}

def is_valid(t):
	if len(t) != 10:
		return False
	if t[2] != '-' or t[5] != '-':
		return False
	if t[3:5] not in d:
		return False
	if '-' in t[0:2]:
		return False
	if int(t[0:2]) == 0:
		return 0
	if int(t[0:2]) > int(d[t[3:5]]):
		return False
	tt = t[6:10]
	if tt not in y:
		return False
	return True

s = raw_input()
l = len(s)
i = 0
while i+9 < l:
	tmp = s[i:i+10]
	if is_valid(tmp):
		if tmp in d2:
			d2[tmp] += 1
		else:
			d2[tmp] = 1
	i += 1
mx = 0
res = ""
for key in d2:
	if d2[key] > mx:
		mx = d2[key]
		res = key
print res
