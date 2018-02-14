if __name__ == '__main__':
  inp = "testcase.in"
  arr = [int(x) for x in open(inp, 'r').read().split()[1:]]

  file1 = "A.out"
  file2 = "B.out"

  s = open(file1, 'r').read().split()
  t = open(file2, 'r').read().split()

  if s[0] == "Fail" or t[0] == "Fail":
    print s == t
  else:
    print True
