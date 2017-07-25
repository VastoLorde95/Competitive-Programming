def maxim(h, a, s):
	if h>0 and a>0:
		if s == 1:
			if (h,a) not in d:
				d[(h,a)] = max(maxim(h-20, a+5, 2), maxim(h-5, a-10, 2)) + 1
			return d[(h,a)]
		else:
			d[(h,a)] = maxim(h+3, a+2, 1) + 1
			return d[(h,a)]
	else:
		return 0
t = input()
for i in range(t):
	d = {}
	health, armour = [int(x) for x in raw_input().split()]
	print maxim(health+3,armour+2,1)
