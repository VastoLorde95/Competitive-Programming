testcase=0
fail="False"

while [ $testcase -lt 100 ] 
do
	python gen.py > testcase.in
	./my/C < testcase.in > A.out
	./correct/thread < testcase.in > B.out
	result=$(python check.py)
#	if [ "$result" == "$fail" ]
#	then
#		echo "Wrong Answer!"
#		break
#	fi
	testcase=`expr $testcase + 1`
	echo $testcase, $result
done
