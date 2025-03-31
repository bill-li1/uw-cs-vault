#!/usr/bin/bash

if [ $# -ne 1 ]; then
	echo "need argument" >&2
	exit 1
fi
echo "${1}" | egrep -e "^[0-9]+$" > /dev/null
if [ $? -ne 0 ]; then
	echo "need positive int" >&2
	exit 1
fi
if [ ! -r students.csv ]; then
	echo "students.csv doesn't exist or isn't readable" >&2
	exit 1
fi
tmp1=$(mktemp)
tmp2=$(mktemp)
cp students.csv $tmp1
num=1
while [ $num -le $1 ]; do
	if [ ! -r a${num}.csv ]; then
		echo "a${num}.csv doesn't exist or isn't readable" >&2
		exit 1
	fi
	join -t',' $tmp1 a${num}.csv > $tmp2
	mv $tmp2 $tmp1
	num=$((num+1))
done
mv $tmp1 totals.csv
