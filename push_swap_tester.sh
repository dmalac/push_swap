#!/bin/bash

ELEMENTS=(100 500)
REPEAT=1000

for item in ${ELEMENTS[@]};
do
	## Creates files with numbers 1 - 100 and 1 - 500, if not already present
	if [ ! -f "input_"$item".txt" ]
	then
		echo "Creating a file containing $item integers..."
		seq 1 $item > "input_"$item".txt"
	fi
	RESULT=0
	for (( i=0 ; i<$REPEAT ; i++ ))
	do
		if [ $(( $i % ($REPEAT / 100) )) -eq 0 ]
		then
			echo -n "."
		fi
		INPUT=$(sort -R "input_"$item".txt")	# scrambles the input
		RESULT=$(($RESULT + $(./push_swap $INPUT | wc -l) ))
	done
	echo ""
	echo "$item integers > test run $i times, average result is $(($RESULT / $i))"
done
