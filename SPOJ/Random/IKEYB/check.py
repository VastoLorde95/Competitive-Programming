ans = open('ans.out','r').read().split()
out = open('ikeyb.out','r').read().split()
print len(ans)
for i in xrange(len(ans)):
	if ans[i] != out[i]:
		print ans[i-3],ans[i-2],ans[i-1],ans[i]
		print out[i-3],out[i-2],out[i-1],out[i]
		print i
		print
