n = input()
a = [int(x) for x in raw_input().split()]
for num in a:
	res = num
	cnt = 0
	while num%5 == 0:
		num /= 5
		cnt += 1
	num = res
	while cnt > 0 and num%2 == 0:
		num /= 2;
		cnt -= 1
	while cnt > 0:
		res *= 4
		cnt -= 2
	print res 
