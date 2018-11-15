#!\bin\sh
echo "options are :\n+:add\n-:substract\n*:multiply\n/:divide "
echo "enter the 2 nos "
  read a
  read b
echo "\nenter your choice "
read ch
Savitha Shetty ,Asst  Professor ,Dept of CSE                                                                                                        Page 10
case $ch in
'+') y=`expr $a + $b`
  echo "sum = $y";;
'-') y=`expr $a - $b`
  echo "diff = $y";;
'*') y=`expr $a \* $b`
  echo "product = $y";;
'/')y=`expr $a / $b`
 echo "division = $y";;
*)echo "invalid choice ";;
esac