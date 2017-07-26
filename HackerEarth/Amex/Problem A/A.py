from math import *
from fractions import *


d = {'0':'6','1':'8','2':'9','3':'1','4':'0','5':'2','6':'4','7':'3','8':'5','9':'7'}
p = [4, 5, 2, 6, 1, 3]

mtoi = {'Jan': 1, 'Feb': 2, 'Mar': 3, 'Apr':4, 'May':5, 'Jun':6, 'Jul':7, 'Aug':8, 'Sep':9, 'Oct':10, 'Nov':11, 'Dec':12}

drev = {}
for key in d:
	drev[d[key]] = key
	
prev = [5, 3, 6, 1, 2, 4]

def convert(s):
	ret = ''
	for c in s:
		ret += d[c]
	
	length = len(s)	
	l = ['.'] * length
	
	for i in xrange(length): l[p[i]-1] = ret[i]
		
	ret = ""
	for e in l: ret += e
	return ret

def revert(s):
	ret = ''
	for c in s:
		ret += drev[c]
	
	length = len(s)	
	l = ['.'] * length
	
	for i in xrange(length): l[prev[i]-1] = ret[i]
		
	ret = ""
	for e in l: ret += e
	return ret

def getdatetup(s):
	l = s.split('-')
	l[1] = str(mtoi[l[1]])
	l = l[::-1]
	
	for i in xrange(len(l)):
		l[i] = int(l[i])
	
	return tuple(l)

n = input()

enroll = []

for i in xrange(n):
	t = raw_input().split()
	d1 = getdatetup(t[-2])
	d2 = getdatetup(t[-1])
	t[-2] = d1
	t[-1] = d2
	
	enroll.append(t)


m = input()

spend = []

cust_total = {}
cust_online = {}

for i in xrange(m):
	t = raw_input().split()
	t[0] = convert(t[0])
	spend.append(t)
	
	cust_total[t[0]] = 0
	cust_online[t[0]] = 0

for order in spend:
	ppl = order[0]
	day = getdatetup(order[2])
	merch = order[1]
	amt = int(order[3])
	
	cust_total[ppl] += amt
	
	for e in enroll:
		if e[0] == ppl:
				if e[-2] <= day <= e[-1] and merch == e[1] and e[3] == 'Online':
						cust_online[ppl] += amt

res = []
for key in cust_total:
	res.append((revert(key), cust_online[key]*1.0/cust_total[key]))	
res.sort()

for cust in res:
	print cust[0], int(round(cust[1]*100))

