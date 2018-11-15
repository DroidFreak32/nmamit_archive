#!/bin/sh
y=`expr $1 % $2`
if [ $y -eq 0 ]
then
echo " $1 is divisible by $2 "
else
echo " $1 not divisible by $2 "
fi