#!/bin/sh
echo "Enter the string"
read str
if [ -z "$str" ]
then
echo "NULL STRING"
else
y=`expr "$str" : '.*'`
echo "String length is :$y"
fi
if [ $y -ge 6 ]
then
echo "First 3 characters:"
z=`expr "$str" : '\(...\).*'`
echo $z
echo "Last three characters:"
x=`expr "$str" : '.*\(...\)'`
echo $x
fi


