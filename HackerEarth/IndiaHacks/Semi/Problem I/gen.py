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

'''
Available Functions

genRandomArray(size, low, high)
To robustly test on arrays, generate arrays with all zeroes, all same numbers etc manually

genRandomString(size, lowchar, highchar)
To robustly test on strings, manually generate strings made up of the same character

genRandomPermutation(size)

genRandomTree(size)
genRandomWeightedTree(size, low, high)
genRandomGraph(nodes, edges)
genRandomConnectedGraph(nodes, edges)
genRandomWeightedGraph(nodes, edges, low, high)

To robustly test on graphs, manually generate star graphs, linear chain graph, complete graph etc

Generate Test Case Below!
'''
def shortestPath(v, n, edges):
	vis = {}
	d = {}
	pre = {}
	
	inf = 10**9
	for i in xrange(1,n+1):
		d[i] = inf
	
	l = [(0, v)]
	
	d[v] = 0
	pre[v] = -1
	
	start = v
	
	while len(l) > 0:
		v = l[-1][1]
		l.pop()
		
		if v in vis: continue
		
		vis[v] = 1
		
		for e in edges:
			a, b, c = e
			if a != v and b != v: continue
			if b == v: a,b = b,a
			
			if b in vis: continue
			
			if d[v] + c < d[b]:
				d[b] = d[v] + c
				pre[b] = v
				l.append((d[b], b))
		
		l.sort()
	
	end = start+1
	if end > n:
		end = start - 1
	path = []
	while end != -1:
		path.append(end)
		end = pre[end]
	return path
		

if __name__ == "__main__":
	T = 1
	N = 8
	C = 10
	print T
	for t in xrange(T):
		n = randrange(5, N+1)
		m = randrange(n-1, (n*(n+1))/2 - 5)
		
		print n, m
		
		edges = genRandomWeightedGraph(n, m, 1, C)
		for e in edges:
			print e[0], e[1], e[2]
		
		l = shortestPath(randrange(1,n+1), n, edges)
		
		s = randrange(2, len(l) + 1)
		d = {}
		for j in xrange(s):
			r = randrange(1,len(l))
			while r in d:
				r = randrange(len(l))
			d[r] = 1
	
		print s
		for key in d:
			print l[key],
		print
			
		
'''

End of main!

'''
