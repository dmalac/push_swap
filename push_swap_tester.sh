#!/bin/bash

ELEMENTS=(100 500)
REPEAT=2000
## If you want the tester to also test the bonus, set RUN_CHECKER to 1
RUN_CHECKER=1

for item in ${ELEMENTS[@]};
do
	## Creates files with numbers 1 - 100 and 1 - 500, if not already present
	if [ ! -f "input_"$item".txt" ]
	then
		echo "Creating a file containing $item integers..."
		seq 1 $item > "input_"$item".txt"
	fi
	RESULT=0
	CHECKER_OK=0
	for (( i=0 ; i<$REPEAT ; i++ ))
	do
		if [ $(( $i % ($REPEAT / 100) )) -eq 0 ]
		then
			echo -n "."
		fi
		INPUT=$(sort -R "input_"$item".txt")	# scrambles the input
		RESULT=$(($RESULT + $(./push_swap $INPUT | wc -l) ))
		if [ $RUN_CHECKER -eq 1 ]
		then
			if [ $(./push_swap $INPUT | ./checker $INPUT) == "OK" ]
			then
				CHECKER_OK=$(($CHECKER_OK + 1))
			fi
		fi
	done
	echo ""
	echo "$item integers > test run $i times, average result is $(($RESULT / $i))."
	if [ $RUN_CHECKER -eq 1 ]
	then
		echo "The checker returned \"OK\" in $CHECKER_OK cases."
	fi
done
