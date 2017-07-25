from random import *
n = 1<<18
s1 = ""
s2 = ""
for i in xrange(n):
	s1 += chr(ord('a') + randrange(26))
	s2 += chr(ord('a') + randrange(26))
print s1
print s2

