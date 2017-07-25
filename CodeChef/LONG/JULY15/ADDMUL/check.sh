#!/bin/bash
python gen2.py > 1.in
./A < 1.in > A.out
./brute < 1.in > B.out
python checker.py
