#!/bin/sh
if [ $# -gt 0 ]
then
for i in "$@"
do
printf "$i "
done
n=$#
echo " "
echo "in reverse order"
while [ $n -gt 0 ]
do
eval printf "\$$n "
printf " "
n=`expr $n - 1`
done
else
echo "no command line argument"
fi