# Enter your code here. Read input from STDIN. Print output to STDOUT
n = input()
s = raw_input()
d = {}
for c in s:
    if c in d:
        d[c] += 1
    else:
        d[c] = 1
ans = 0
for key in d:
    ans += ((d[key]*(d[key]+1))/2)
print ans
