#!/bin/sh
if [ $# -eq 0 ]
then
echo"No arguments"
else
grep $1 $2
fi
