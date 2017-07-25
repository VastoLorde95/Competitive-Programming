import sys
d = {}
indegree = {}
q = []
count = 0
for line in sys.stdin:
	line = line.split()
	a = line[0]
	indegree[a] = 0
	for i in xrange(1, len(line)-1):
		if line[i] in d:
			if a not in d[line[i]]:
				indegree[a] += 1
			d[line[i]].add(a)
		else:
			d[line[i]] = {a}
			indegree[a] += 1
for key in indegree:
	if indegree[key] == 0:
		q.append(key)
		count += 1
while len(q) > 0:
	a = q.pop()
	if a in d:
		for j in d[a]:
			indegree[j] -= 1
			if indegree[j] == 0:
				q.append(j)
				count += 1
print count
