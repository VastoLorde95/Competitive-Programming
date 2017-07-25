from math import ceil
r, x1, y1, x2, y2 = [int(x) for x in raw_input().split()]
d = (((x2-x1)**2) + ((y2-y1)**2)) ** 0.5
print int(ceil(d/(2*r)))
