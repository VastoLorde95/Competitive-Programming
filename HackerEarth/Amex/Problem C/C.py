from math import *
from fractions import *
from datetime import *

mtoi = {'Jan': 1, 'Feb': 2, 'Mar': 3, 'Apr':4, 'May':5, 'Jun':6, 'Jul':7, 'Aug':8, 'Sep':9, 'Oct':10, 'Nov':11, 'Dec':12}

def getdatetup(s):
	l = s.split('-')
	l[1] = str(mtoi[l[1]])
	l = l[::-1]
	
	for i in xrange(len(l)):
		l[i] = int(l[i])
	
	return tuple(l)

def date_diff(d1, d2):
	d1 = date(d1[0], d1[1], d1[2])
	d2 = date(d2[0], d2[1], d2[2])
	return (d1 - d2).days

customer_lists = {}
customer_trips = {}
customer_town = {}

n = input()

for i in xrange(n):
	lst = raw_input().split()
	cust = lst[0]
	
	lst[1] = getdatetup(lst[1])
	
	customer_town[cust] = lst[2]
	customer_trips[cust] = 0
	
	lst = lst[1:2] + lst[3:-1]
	
	if cust not in customer_lists:
		customer_lists[cust] = [tuple(lst)]
	else:
		customer_lists[cust].append(tuple(lst))

m = input()

for i in xrange(m):
	lst = raw_input().split()
	
	if lst[4] == 'Y': continue
	
	cust = lst[0]
	
	lst[1] = getdatetup(lst[1])
	
	customer_town[cust] = lst[2]
	customer_trips[cust] = 0
	
	lst = lst[1:2] + lst[3:-2]
	
	if cust not in customer_lists:
		customer_lists[cust] = [tuple(lst)]
	else:
		customer_lists[cust].append(tuple(lst))

def cuscmp(a, b):
	if a[0] != b[0]:
		if a[0] < b[0]: return -1
		return 1
	else:
		if len(a) < len(b): return 1
		elif len(a) > len(b): return -1
		else: return 0
		

for key in customer_lists:
	customer_lists[key].sort(cuscmp)
	
#	print customer_lists[key], key
	
	l = customer_lists[key]
	cur = customer_town[key]
	
	curdate = (1,1,1)
	
	i = 0
	
#	if l[0][-2] != cur and len(l[0][i]) == 3:
#		customer_trips[key] += 1
	
	while i < len(l):
		if cur == customer_town[key]:
			while i < len(lst) and (len(l[i]) == 2 and l[i][-1] == cur): i += 1
		
			if i == len(l): break
			
			customer_trips[key] += 1

			curdate = l[i][0]
			cur = l[i][-1]
			
			i += 1
		else:
			if len(l[i]) == 2:
				d1 = l[i][0]
				if date_diff(d1, curdate) >= 30 and l[i][-1] != customer_town[key]:
					customer_trips[key] += 1
				cur = l[i][-1]
			else:
				#trip
				
				if l[i][-2] == customer_town[key]:
					customer_trips[key] += 1
				else:
					d1 = l[i][0]
					if date_diff(d1, curdate) >= 30:
						customer_trips[key] += 1
				cur = l[i][-1]
			i += 1
			
l = []
	
for key in customer_trips:
	l.append((key, customer_trips[key]))

l.sort()

for ppl in l:
	print ppl[0], ppl[1]
	
