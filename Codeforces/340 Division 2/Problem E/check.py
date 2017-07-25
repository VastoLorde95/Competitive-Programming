file1 = "A.out"
file2 = "B.out"
s1 = open(file1, 'rw+').read()
s2 = open(file2, 'rw+').read()
print s1 == s2
