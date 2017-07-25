d = {'0':"",'1':"",'2':"2",'3':"3",'4':"322",'5':"5",'6':"53",'7':"7",'8':"7222",'9':"7332"}
res = ""
n = input()
temp = raw_input()
s = ""
j = 0
while j < n and temp[j] == "0":
	j += 1
while j < n:
	s += temp[j]
	j += 1
	
if s == "":
	print 0
else:	
	for c in s:
		res += d[c]

	x = []
	for c in res:
		x.append(c)
	x.sort(reverse = True)
	res = ""
	for c in x:
		res += c 
	print res
	
