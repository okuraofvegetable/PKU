from random import *
n = randint(49000,50000)
m = randint(49000,50000)
k = randint(100,n-100)
print "%d %d" % (n,m)
for i in xrange(n-k):
	x = i*100+randint(1,9);
	y = randint(10000,60000)
	print "%d %d %d %d" % (x,y,x,y+randint(10000,20000))
for i in xrange(k):
	x = randint(10000,30000)
	y = randint(60000,100000)
	print "%d %d %d %d" % (x,y,x+randint(20000,40000),y)
for i in xrange(m):
	x = i*100+randint(40,60)
	y = randint(10000,70000)
	print "%d %d" % (x,y)

