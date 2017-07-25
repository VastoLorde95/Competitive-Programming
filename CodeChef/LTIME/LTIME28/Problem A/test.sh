python gen.py > inp.in
./A < inp.in > A.out
./brute < inp.in > B.out
python check.py
