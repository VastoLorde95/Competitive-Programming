file1 = "A.out" # my
file2 = "B.out" # threaded

s = open(file1, 'r').read()
t = open(file2, 'r').read()

l1 = len(s)
l2 = len(t)

print l1, l2
print (l1-l2) / (l2*1.0)
