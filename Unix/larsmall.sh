echo "enter three numbers "
read a
read b
read c
if [ $a -ge $b ] && [ $a -ge $c ]
then echo "largest number " $a
elif [ $b -ge $a ]&&[ $b -ge $c ] 
then echo "largest number "$c
else echo "largest number "$c
fi


if [ $a -le $b ]&&[ $a -le $c ]
then echo "smallest number "$a
elif [ $b -le $a ]&&[ $b -le $c ]
 
then echo "smallest  number "$b
else echo "smallest number "$c
fi

