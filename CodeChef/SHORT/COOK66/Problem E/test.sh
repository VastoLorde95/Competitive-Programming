python gen.py > testcase.in
./E < testcase.in > A.out
./brute < testcase.in > B.out
python check.py
