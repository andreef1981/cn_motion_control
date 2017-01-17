#!/bin/sh
echo "Hello World"

motor=1

for gate in `seq 0 4`
do
	for channel in `seq 0 3`
	do
		if [ $gate -eq "0" ] && [ $channel -gt "1" ]
		then
			echo "nothing to do"
		else
			`cat motor2config.txt | \
			sed s/Gate3\\\\[0\\\\]/Gate3[$gate]/g | \
			sed s/Chan\\\\[1\\\\]/Chan[$channel]/g | \
			sed s/Motor\\\\[2\\\\]/Motor[$motor]/g | \
			sed s/EncTable\\\\[2\\\\]/EncTable[$motor]/g |\
			sed s/Coord\\\\[2\\\\]/Coord[$motor]/g |\
			sed s/\\[\\&\\]2/\\\\\\&${motor}/g |\
			sed s/\\#2/\\#${motor}/g \
			> Motor_${motor}_Gate3${gate}Chan${channel}.txt`
			#
			motor=$((motor + 1))
		fi
	done
done
#Coord[2]
