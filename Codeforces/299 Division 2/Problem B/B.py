#Tavas and Saddas
s = raw_input()
l = len(s)
cnt, b = (1<<l)-2, ""
for c in s:
	if c == '7': b += '1'
	else: b += '0'
print cnt+(int(b,2)+1)
