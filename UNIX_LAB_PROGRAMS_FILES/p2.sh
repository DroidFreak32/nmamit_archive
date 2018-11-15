#!/bin/sh
echo "enter the divident"
read n
echo "enter the divisor"
read m
y=`expr $n % $m`
if [ $y -eq 0 ]
then
echo " $n is divisible by $m "
else
echo " $n not divisible by $m "
fi