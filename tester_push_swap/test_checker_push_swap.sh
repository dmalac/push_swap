#!/bin/bash

#define test cases (array containing 3, 5, 100, 500)
TEST_CASES=(3 5 100 500)
INPUT_FILE=input.txt

PUSH_SWAP=../push_swap
CHECKER=../checker
CHECKER_MAC=../checker_Mac

REPEATS=0

#create test input file: seq 1 array[i] > input$(array[i]).txt
for (( n=0 ; n<4 ; n++ ))
do

	seq 1 ${TEST_CASES[n]} > $INPUT_FILE

	SAME=0
	DIFFERENT=0

	for (( i=1 ; i<=$REPEATS ; i++ ))
	do
		INPUT=$(sort -R $INPUT_FILE)
		MY_RESULT=$(./$PUSH_SWAP $INPUT | ./$CHECKER $INPUT)
		CONTROL_RESULT=$(./$PUSH_SWAP $INPUT | ./$CHECKER_MAC $INPUT)
		if [ $MY_RESULT == $CONTROL_RESULT ]
		then
			SAME=$(($SAME+1))
		else
			DIFFERENT=$(($DIFFERENT+1))
		fi
		# echo $INPUT $MY_RESULT $CONTROL_RESULT
	done

#	echo "I've run $(($SAME+$DIFFERENT)) tests with ${TEST_CASES[n]} elements."
	# if [ $DIFFERENT -eq 0 ]
	# then
	# 	echo "All of them were the same."
	# else
	# 	echo "The results were different in $DIFFERENT cases."
	# fi
done

# inputs with errors
declare -a ERROR_INPUT=("1 4 b" "4 9 4" "36 9 4 999999999999999999" "24 *7");

for item in "${ERROR_INPUT[@]}"
do
	echo "Testing with $item"
	MY_RESULT=$(./$PUSH_SWAP $item | ./$CHECKER $item)
	CONTROL_RESULT=$(./$PUSH_SWAP $item | ./$CHECKER_MAC $item)
	# if [ $MY_RESULT == $CONTROL_RESULT ]
	# then
	# 	echo "\"$item\": $MY_RESULT"
	# else
	# 	echo "\"$item\": FAIL - expected $CONTROL_RESULT, got $MY_RESULT"
	# fi
done