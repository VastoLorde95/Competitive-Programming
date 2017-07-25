'''
f(i) = sum of digits of i
g(i,j) = sum k = i-1 to j-1 f(i)

if x < 10**18 =>f(x + 10**18) = f(x) + 1

if g(x+1, x+(10**18)) = s
=> g(x+2, x+(10**18)+1) = s + f(x+(10**18)) - f(x)
= s + f(x) + 1 - f(x)
= s+1

=> the sum increases by just 1

so if g(10**18)%a == r
then we shift the interval [1, 10**18-1] by (a-r) steps to the right
'''

a = input()
r = (81000000000000000000)%a

print a-r, a-r+(10**18)-1
