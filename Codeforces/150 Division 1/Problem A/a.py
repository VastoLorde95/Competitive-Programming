from math import *
k,b,n,t = [int(x) for x in raw_input().split()]
print int(ceil((k*n + log((k+b)/(1.0*k*t +b)))/k))-1
