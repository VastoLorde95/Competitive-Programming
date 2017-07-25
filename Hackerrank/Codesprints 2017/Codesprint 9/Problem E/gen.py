from random import *
from numpy import random

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
	
	l = []
	for i in xrange(1, N+1):
		for j in xrange(i+1, N+1):
			l.append((i,j))
	
	return sample(l, E)

''' Undirected, no multiedges, no self-loops, connected '''
def genRandomConnectedGraph(N, E):
	E -= N-1
	tree = genRandomTree(N)
	edges = {}
	for edge in tree:
		edges[edge] = 1

	l = []	
	for i in xrange(1, N+1):
		for j in xrange(i+1, N+1):
			if (i,j) in edges or (j,i) in edges: continue
			l.append((i,j))
				
	ret = sample(l, E)
	ret += tree
	
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

def genRandomGraph2(N, E, L, R):
	ans = []
	for i in xrange(E):
		u, v = sample(range(N), 2)
		u += 1
		v += 1
		ans.append((u,v, randrange(L, R+1)))
	return ans

if __name__ == '__main__':
	N = 100
	M = 100
	
	n = randrange(2, N+1)
	m = randrange(1, max((n*(n-1))/2, M))
	
	
	print n, m
	g = genRandomGraph2(n, m, 1, 999)
	for edge in g:
		print edge[0], edge[1], edge[2]
	
