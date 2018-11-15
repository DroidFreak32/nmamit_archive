#!/bin/sh
if [ $# -eq 0 ]
then
  echo "enter the pattern"
read pattern
echo"enter filename"
read filename
else
pattern=$1
filename=$2
fi
sh f1.sh $pattern $filename
