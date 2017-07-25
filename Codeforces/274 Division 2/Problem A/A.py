a = input()
b = input()
c = input()

l = [a+b+c, (a+b)*c, a+(b*c), (a*b)+c, a*(b+c), a*b*c]
print max(l)
