#! /bin/usr
echo "enter a string"
read s
x=`expr $s : '.*'`
echo "$x"
m=`expr $s : '\(...\).*'`
echo "the substring is $m"
echo "enter character to be located"
read a
n=`expr $s : '[^'$a']*'$a''`
echo "the position of $a is $n"
