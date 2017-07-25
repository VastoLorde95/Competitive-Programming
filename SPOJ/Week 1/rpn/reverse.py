no_of_iter = input()
N = 0
count = 0
lis = []
while count < no_of_iter:
	num1, num2 = raw_input().split()
	lis.append((num1,num2))
	count+=1
for sample in lis:
	num1, num2 = sample
	l1, l2 = len(num1), len(num2)
	number = ''
	l, i, carry = min(l1, l2), 0, 0
	while i < l:
		x = int(num1[i]) + int(num2[i]) + carry
		summ = x%10
		number += str(summ)
		carry, i = x/10, i + 1
	if carry == 0:
		if l1>l2:
			number += num1[i:]
		elif l2>l1:
			number += num2[i:]
	else:
		if l1>l2:
			while i <l1:
				x = carry + int(num1[i])
				summ = x % 10
				number += str(summ)
				carry, i = x/10, i + 1
		elif l2>l1:
			while i <l2:
				x = carry + int(num2[i])
				summ = x % 10
				number += str(summ)
				carry, i = x/10, i + 1
		else:
			number += str(carry)
			carry = 0
	if carry != 0:
		number +=str(carry)
	print int(number)
