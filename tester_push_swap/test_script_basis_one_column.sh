#!/bin/bash

# minimum and maximum number of tranches to be tested:
min=5
max=7
TRANCHES=$min
NAME=push_swap

# checks whether the necessary executables are present and compiles the missing ones
while [ $TRANCHES -le $max ]
do
	if [ ! -f "$NAME"_$TRANCHES ]
	then
		make re TRANCHE_MODIFICATION="-D TRANCHES=$TRANCHES"
		mv $NAME "$NAME"_$TRANCHES
	fi
	TRANCHES=$((TRANCHES + 1))
done

# testing

PREVIOUS_ID=1005
ID=1
REPEAT=1995
while [ $ID -le $REPEAT ]
do
	INPUT=$(sort -R input.txt)
	TRANCHES=$min
	CHECKER=$(MallocNanoZone=0 ./"$NAME"_$TRANCHES $INPUT | ./checker_Mac $INPUT)
	while [ $TRANCHES -le $max ]
	do
		echo $(($ID + $PREVIOUS_ID)) >> result.txt
		echo $INPUT >> result.txt
		echo $CHECKER >> result.txt
		echo $TRANCHES >> result.txt
		echo $(MallocNanoZone=0 ./"$NAME"_$TRANCHES $INPUT | wc -l) >> result.txt
		echo "*" >> result.txt
		TRANCHES=$((TRANCHES + 1))
	done
	ID=$((ID + 1))
done

#cp result.txt result_backup.txt

tr '\n' ';' < result.txt > temp.txt
sed -i '' 's/;\*;/\*/g' temp.txt
tr '\*' '\n' < temp.txt > result.txt
cat result.txt >> result_total.txt
rm temp.txt #result.txt