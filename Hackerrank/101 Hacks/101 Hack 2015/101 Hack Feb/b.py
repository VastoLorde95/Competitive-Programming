# Enter your code here. Read input from STDIN. Print output to STDOUT
s = raw_input()
n = len(s)+1
l = []
prev = 0
i = n
if s[0] == 'I':
    l.append(i-1)
    l.append(i)
    i -= 2
else:
    l.append(i)
    l.append(i-1)
    prev = 1
    i -= 2
j = 1
while i >= 1:
    if s[j] == 'I':
    
    	:if prev:
	        l = l[:prev] + [i] + l

    else:
        for num in l:
            print num,
        l = []
        l.append(i)
        prev = 0
    j += 1
    i -= 1
    print l
for num in l:
    print num,

