a = input()
for i in range(a):
	n,k,t,f = [int(x) for x in raw_input().split()]
	print n + k*((f-n)/(k-1))
