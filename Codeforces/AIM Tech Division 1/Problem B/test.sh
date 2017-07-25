python gen.py > testcase.in
./B < testcase.in > A.out
./brute < testcase.in > B.out
python check.py
