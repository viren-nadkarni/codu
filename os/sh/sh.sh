#!/bin/sh

clear

Give a string 'operating system'
string="Operating system"

echo "Find the length of the string"
echo ${#string}

echo "Find the location of the character 't'"
expr index "operating system" "t"

echo "Add a character 's' at the last"
echo $string"s"

echo ""
echo "Write a shell script to print the following pattern:"
echo "     1"
echo "    2 2"
echo "   3 3 3"
echo "  4 4 4 4"
echo " 5 5 5 5 5"
echo "6 6 6 6 6 6"

#!/bin/sh
for i in `seq 1 6`
do	
	l=$((6-i))
	for k in `seq 1 $l`
	do
		printf " "
	done
	for j in `seq 1 $i`
	do
		printf $i" "
	done
echo ""
done
echo ""

echo "Consider a file consisting of the foll. structure"
cat file1

echo "Find the names of those who work in the same deparment"
echo "Comp employees:"
grep "Comp" file1 | awk '{print $1}'
echo "Mech employees:"
grep "Mech" file1 | awk '{print $1}'
echo "Electronics employees:"
grep "Electronics" file1 | awk '{print $1}'

echo "Put all the names who have unique designation in different files"
list=`(cat file1 | awk '{print $1}')`
for x in $list
do
	y=`grep $x file1 | awk '{print $3}'`
	echo $x >> $y
done

echo "Add a char '|' before designation"
cat file1 | sed 's/\t\t/\t\t|/'

echo ""
