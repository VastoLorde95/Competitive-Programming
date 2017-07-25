s = raw_input()
d = {}
for c in s:
    if c in d:
        d[c] += 1
    else:
        d[c] = 1
cnt = 0
for key in d:
    if d[key]%2 == 1: cnt += 1
if cnt == 0 or cnt  == 1 or cnt%2 == 1:
    print 'First'
else:
    print 'Second'
                   
