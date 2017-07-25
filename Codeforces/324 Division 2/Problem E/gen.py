from random import *
import numpy

N = 10
a = numpy.random.permutation(N)
b = numpy.random.permutation(N)
print N
for i in a:
	print i+1,
print
for i in b:
	print i+1,
print

