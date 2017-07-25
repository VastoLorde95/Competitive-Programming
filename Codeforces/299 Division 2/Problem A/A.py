n = input()
a = n/10
b = n%10
d1 = {2:"twenty",3:"thirty",4:"forty",5:"fifty",6:"sixty",7:"seventy",8:"eighty",9:"ninety"}
d2 = {1:"one",2:"two",3:"three",4:"four",5:"five",6:"six",7:"seven",8:"eight",9:"nine",0:"zero"}

if a == 0 and b == 0:
	print "zero"
elif a == 0:
	print d2[b]
elif a == 1:
	if n == 10:
		print "ten"
	if n == 11:
		print "eleven"
	if n == 12:
		print "twelve"
	if n == 13:
		print "thirteen"
	if n == 14:
		print "fourteen"
	if n == 15:
		print "fifteen"
	if n == 16:
		print "sixteen"
	if n == 17:
		print "seventeen"
	if n == 18:
		print "eighteen"
	if n == 19:
		print "nineteen"
else:
	if b == 0:
		print d1[a]
	else:
		s = d1[a] + '-' + d2[b]
		print s
