#!/bin/bash

# minimum and maximum number of tranches to be tested:
min=4
max=15
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

# REWRITE SO THAT THERE IS A COLUMN RESULT AND A COLUMN NO. OF TRANCHES ? OR NOT ? yes -> can get avg by input e.g

PREVIOUS_ID=110
ID=1
REPEAT=40
while [ $ID -le $REPEAT ]
do
	INPUT=$(sort -R input.txt)
	echo $(($ID + $PREVIOUS_ID)) >> result.txt
	echo $INPUT >> result.txt
	TRANCHES=$min
	echo $(MallocNanoZone=0 ./"$NAME"_$TRANCHES $INPUT | ./checker_Mac $INPUT) >> result.txt
	while [ $TRANCHES -le $max ]
	do
		echo $(MallocNanoZone=0 ./"$NAME"_$TRANCHES $INPUT | wc -l) >> result.txt
		TRANCHES=$((TRANCHES + 1))
	done
	ID=$((ID + 1))
	echo "*" >> result.txt
done

#cp result.txt result_backup.txt

tr '\n' ';' < result.txt > temp.txt
sed -i '' 's/;\*;/\*/g' temp.txt
tr '\*' '\n' < temp.txt > result.txt
cat result.txt >> result_total.txt
rm temp.txt result.txt