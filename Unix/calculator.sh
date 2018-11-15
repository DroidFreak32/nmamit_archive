#! /bin/usr
echo "enter 2 numbers"
read a
read b
echo "enter the choice"
read c
case $c in
 '+') y=`expr $a + $b`
       echo "$y";;
'-') y=`expr $a - $b`
   echo "$y";;
'*') y=`expr $a \* $b`
  echo "$y";;
'/') y=`expr $a / $b`
echo "$y";;
*)echo "invalid"
esac

