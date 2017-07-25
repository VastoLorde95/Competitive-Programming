file1 = "A.out"
file2 = "B.out"

s = open(file1, 'r').read().split()
t = open(file2, 'r').read().split()

print s == t
