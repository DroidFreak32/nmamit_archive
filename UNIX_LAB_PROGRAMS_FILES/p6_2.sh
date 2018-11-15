#!/bin/sh
echo "enter the string"
read str
t=`expr "$str" : '.*'`
echo "the length of the string is $t"
if [ $t -ge 6 ]
then
p=`expr "$str" : '\(...\).*'`
q=`expr "$str" : '.*\(...\)'`
echo "the first three character are $p"
echo "the last three character are $q"
else
echo "length of the string iss  less thn 6"
fi