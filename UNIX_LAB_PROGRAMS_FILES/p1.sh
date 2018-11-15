#!/bin/sh
echo "plz enter the three numbers"
read x
read y
read z
if [ $x -ge $y ] && [ $x -ge $z ]
then
   echo "$x is the largest number"
elif [ $y -ge $x ] && [ $y -ge $z ]
then
   echo "$y is the largest number"
else
  echo "$z is the largest number"
fi
if [ $x -lt $y ] && [ $x -lt $z ]
then
   echo "$x is the smallest number"
   elif [ $y -lt $x ] && [ $y -lt $z ]
      then
      echo "$y is the smallest number"
      else
      echo "$z is the smallest number"
 fi