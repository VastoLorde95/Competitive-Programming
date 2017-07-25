file1 = "A.out"
file2 = "B.out"
print open(file1, 'r').read().replace(' ','') == open(file2, 'r').read().replace(' ','')
