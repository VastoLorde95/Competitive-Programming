testcase=0
fail="False"

while [ $testcase -lt 10000 ] 
do
	pypy gen.py > testcase.in
	./A < testcase.in > A.out
	./brute < testcase.in > B.out
	result=$(python check.py)
	
	if [ "$result" == "$fail" ]
	then
		echo "Wrong Answer!"
		break
	fi
	testcase=`expr $testcase + 1`
	echo $testcase, $result
done
