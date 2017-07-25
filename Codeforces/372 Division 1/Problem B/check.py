file1 = "A.out"
#file2 = "B.out"

s = open(file1, 'r').read().split()
#t = open(file2, 'r').read().split()

if "dis" in s: print False
else: print True

#print s == t
