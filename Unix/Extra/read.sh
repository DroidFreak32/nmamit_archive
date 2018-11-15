#!/bin/sh
#read.sh:interactive version,uses read to accept two inputs
#
echo "enter the pattern to be searched:\c"
read pname
echo "enter the file to be used:\c"
read fname
echo "searching for pattern $pname from file $fname"
grep $pname $fname
echo"selected records shown above"
