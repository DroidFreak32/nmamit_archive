printf "enter three numbers "
read a
read b
read c
if [ $a -ge $b ]&&[ $a -ge $c ]
then echo "$a is the largest number "
else if [ $b -ge $a ]&&[ $b -ge $c ]
 
 then echo "$b is the largest number "
else "$c is the largest number "
fi
fi

if [ $a -le $b ]&&[ $a -le $c ]
then echo "$a is the smallest number "
else if [ $b -le $a ]&&[ $b -le $c ]
 
 then echo "$b is the smallest  number "
else "$c is the smallest number "
fi
fi




