#!/bin/sh
str=tanu
echo “string:$str”
echo “lengh of string:”
z=`expr “$str”:’.*’`
echo $z
echo “substring is”
z=`expr “$str”:’.*\(...\)’`
echo $z
echo “position of character n is”
z=`expr “$str”:’[^n]*n’`
echo $z
