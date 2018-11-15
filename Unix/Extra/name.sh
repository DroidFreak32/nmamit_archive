#!/bin/sh
echo "Enter the name :"
read name
if [ -z "$name" ]
then
	echo "Null string"
else
	y=`expr "$name" : '.*'`
	echo "Name length is $y"
fi
if [ $y -ge 6 ]
then
	echo "First 3 characters:"
	z=`expr "$name" : '\(...\).*'`
	echo $z
	echo "Last 3 characters:"
        x=`expr "$name" : '.*\(...\)'`
        echo $x
else
	echo "Name has less than 6 characters"
fi
