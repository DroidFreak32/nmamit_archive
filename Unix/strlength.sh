#! /bin/usr
echo "enter a name"
read s
x=` expr $s : '.*'`
echo "$x"
if [ $x -gt 5 ]
then 
  m=`expr $s : '\(...\).*'`
  n=`expr $s : '.*\(...\)'`
  echo "the first 3 characters of $s are $m and
the last 3 characters of $s is $n"
else
 echo "$s contains $x characters which is less than 6"
fi
  
 
