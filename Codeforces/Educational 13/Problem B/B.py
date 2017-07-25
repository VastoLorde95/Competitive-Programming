y = input()
x = y

leap = False
if (x%4 == 0 and x%100 != 0) or x%400 == 0:
	leap = True

while True:
	cnt = 365
	y += 1
	
	if y%4 == 0 and y%100 != 0:
		cnt = 366
	if y%400 == 0:
		cnt = 366
	
	if cnt == 366 and not leap: continue
	if cnt != 366 and leap: continue;
	
	for i in xrange(1, ):
		
	
	
