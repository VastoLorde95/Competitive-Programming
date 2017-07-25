python gen.py > inp3.in
./FF < inp3.in > A
./brute < inp3.in > B
python check.py
