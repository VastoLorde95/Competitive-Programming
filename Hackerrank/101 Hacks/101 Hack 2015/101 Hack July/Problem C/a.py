s = "ylv2cl4cgna3vetwufxrsftouqzv2sxsnvyzfyisjqlqxouyylmswhwdvj2rehwchmmhkbqxomphnshkdqpcreninlnyszdhmkaf"
t = ""
for c in s:
	if '0' <= c and c <= '9':
		d = ord(c) - 48
		t = t*d
	else:
		t += c
print t
