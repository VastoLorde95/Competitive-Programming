# Enter your code here. Read input from STDIN. Print output to STDOUT
s = raw_input()
d = {}
for c in s:
    if c in d:
        d[c] += 1
    else:
        d[c] = 1
d2 = {}
for key in d:
    if d[key] in d2:
        d2[d[key]] += 1
    else:
        d2[d[key]] = 1
if len(d2) > 2:
    print "NO"
elif len(d2) == 1:
    print "YES"
else:
    l = []
    for key in d2:
        l.append((key, d2[key]))
    
    if l[0][0] < l[1][0]:
        l[0], l[1] = l[1], l[0]
    
    if (l[0][0]-l[1][0])*l[0][1] == 1:
        print "YES"
    elif l[1][0]*l[1][1] == 1:
        print "YES"
    else:
        print "NO"
    
