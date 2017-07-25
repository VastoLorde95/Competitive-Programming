python gen.py > testcase.in
time ./A < testcase.in > A.out
time ./bencmark < testcase.in > B.out
python check.py
