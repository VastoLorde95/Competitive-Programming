from random import *

''' Generate a random array of integers with elements in the range [L, R] '''
def genRandomArray(N, L, R):
	a = [randrange(L,R+1) for _ in xrange(N)]
	return a

''' Generate a random string from characters in the range [A, B]'''
def genRandomString(N, A, B):
	l = genRandomArray(N, ord(A), ord(B))
	s = ''
	for char in l: s += chr(char)
	return s

''' Generate a random permutation of [1, 2 ... N] '''
def genRandomPermutation(N):
	permutation = range(1, N+1)
	shuffle(permutation)
	return permutation

''' Generate a random unweighted tree'''
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

''' Generate a random weighted tree '''
def genRandomWeightedTree(N, L, R):
	weigths = genRandomArray(N-1, L, R)
	tree = genRandomTree(N)
	wtree = []
	
	for i in xrange(0,N-1):
		u, v, w = tree[i][0], tree[i][1], weigths[i]
		wtree.append((u, v, w))
	
	return wtree

''' Undirected, no multiedges and no self-loops '''
def genRandomGraph(N, E):
	edges = {}
	
	if N == 1: return []
	
	for i in xrange(E):
		u = randrange(1,N+1)
		v = u
		while v == u: v = randrange(1,N+1)
		
		while (u,v) in edges or (v,u) in edges:
			u = randrange(1,N+1)
			v = u
			while v == u: v = randrange(1,N+1)
		
		edges[(u,v)] = 1
	
	ret = []
	for edge in edges: ret.append(edge)
	
	return ret

''' Undirected, no multiedges, no self-loops, connected '''
def genRandomConnectedGraph(N, E):
	E -= N-1
	tree = genRandomTree(N)
	edges = {}
	for edge in tree:
		edges[edge] = 1
	
	for i in xrange(E):
		u = randrange(1,N+1)
		v = u
		while v == u: v = randrange(1,N+1)
		
		while (u,v) in edges or (v,u) in edges:
			u = randrange(1,N+1)
			v = u
			while v == u: v = randrange(1,N+1)
		
		edges[(u,v)] = 1
	
	ret = []
	for edge in edges: ret.append(edge)
	
	return ret

''' Undirected, no multiedges, no self-loops, can be forced to be connected '''
def genRandomWeightedGraph(N, E, L, R, connected = False):
	graph = []
	if not connected:
		graph = genRandomGraph(N, E)
	else:
		graph = genRandomConnectedGraph(N, E)
	
	weights = genRandomArray(E, L, R)
	
	wgraph = []
	for i in xrange(E):
		u, v, w = graph[i][0], graph[i][1], weights[i]
		wgraph.append((u,v,w))
	return wgraph

def oye():
	n = 20
	p = 2
	k = 5
	
	print n, p, k
	r = 6
	
	print r,	
	for i in xrange(r):
		print 2*(i+1),
	print
	
	s = 0	
	print s,
	for i in xrange(s):
		print 3*i + 1,
	print

if __name__ == '__main__':
	oye()
	
	exit()
	
	N = 100
	
	n = randrange(1, N+1)
	p = randrange(1, N+1)
	
	k = randrange(1, 51)
	k = min(k, n)
	
	r = randrange(n+1)
	A = sample(range(n), r)
	
	s = randrange(n+1)
	B = sample(range(n), r)
	
	print n, p, k
	print r,
	for x in A: print x+1,
	print
	print s,
	for x in B:	print x+1,
	print
