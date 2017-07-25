from random import *

def genRandomArray(N, L, R):
	a = [randrange(L,R+1) for _ in xrange(N)]
	return a

def genRandomPermutation(N):
	permutation = range(1, N+1)
	shuffle(permutation)
	return permutation

def genRandomTree(N):
	edges = []	
	for u in xrange(2,N+1):
		v = randrange(1,u)
		edges.append([u,v])
		
	permutation = genRandomPermutation(N)
	
	for i in xrange(0,N-1):
		u, v = edges[i]
		u = permutation[u-1]
		v = permutation[v-1]
		edges[i] = (u,v)
	return edges


if __name__ == "__main__":
	t = 5
	print t
	for _ in xrange(t):
		n = randrange(1, 11)
		print n
		
		c = genRandomArray(n, 1, 11)

		for x in c:
			print x,
		print
		
		tree = genRandomTree(n)
		for edge in tree:
			print edge[0], edge[1]

'''

End of main!

'''
