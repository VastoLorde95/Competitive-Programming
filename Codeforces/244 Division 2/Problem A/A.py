ans, c, n = 0, 0, input()
l = [int(x) for x in raw_input().split()]
for num in l:
	if num == -1:
		if c == 0: ans += 1
		else: c -= 1
	else: c += num
print ans
