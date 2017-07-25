from math import *
from fractions import *

def solve():
	n = input()
	w = raw_input().split()
	l = len(w[0])
	lis = []
	for i in xrange(l):
		for j in xrange(i+1,l):
			t = w[0][i:j+1]
			ok = True
			for st in w:
#				print t, st
				if t not in st:
					ok = False
					break
			if ok:
				lis.append(t)
	tmp = []
	mx = 0
	for st in lis:
		if len(st) > mx:
			mx =len(st)
	for st in lis:
		if len(st) == mx:
			tmp.append(st)
	if mx == 0:
		print
	else:
		tmp.sort()
		print tmp[0]
			
			
	return
for _ in xrange(input()):
	solve()
