l = [4, 7, 47, 74, 444, 447, 474, 477, 744, 747, 774, 777]
n = input()
flag = 0
for i in l:
	if n%i == 0:
		flag = 1
if flag:
	print "YES"
else:
	print "NO"
