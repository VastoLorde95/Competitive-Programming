python gen.py > inp2.in
./E < inp2.in > A.out
./brute < inp2.in > B.out
python check.py
