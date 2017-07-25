n = input()
cnt = 0
cmv = 1
tot = 0
while tot+cmv <= n:
	tot += cmv
	cnt += 1
	cmv += (cnt+1)
print cnt
