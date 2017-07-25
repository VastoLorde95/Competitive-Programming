testcase=0
fail="False"

while [ $testcase -lt 10000 ] 
do
	python gen.py > testcase.in
	python A.py < testcase.in > A.out
	python B.py < testcase.in > B.out
	result=$(python check.py)
	
	if [ "$result" == "$fail" ]
	then
		echo "Wrong Answer!"
		break
	fi
	testcase=`expr $testcase + 1`
	echo $testcase, $result
done
