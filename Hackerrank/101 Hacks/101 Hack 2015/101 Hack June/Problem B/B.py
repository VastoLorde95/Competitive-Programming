# Enter your code here. Read input from STDIN. Print output to STDOUT
for _ in xrange(input()):
    r, s = [int(x) for x in raw_input().split()]
    
    a = (r%s)/(s*1.0)
    if a <= 0.25:
        print r,
        r %= s
        if r == 0:
            print "0/1"
        else:
            i = 2
            while i*i <= s and r > 0 and s > 0:
                while r%i == 0 and s%i == 0:
                    r /= i
                    s /= i
                i += 1
            print str(r)+'/'+str(s)
    else:
        #print a
        lag = r + (1.0-a)*s
        print int(lag),
        print "0/1"
    
