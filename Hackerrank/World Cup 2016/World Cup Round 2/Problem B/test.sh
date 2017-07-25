python gen.py > test.in
./B < test.in > A.out
./B2 < test.in > B.out
python check.py
