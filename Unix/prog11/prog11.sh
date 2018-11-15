if [ $# -eq 0 ]; then
	echo "Enter the name"
	read name
else
	name=$@
fi

y=`expr "$name" : '.*'`
echo "Length of name: $y"
if [ $y -ge 6 ]; then 
	f=`expr "$name" : '\(...\)'`
	l=`expr "$name" : '.*\(...\)'`
	echo "Extracted string : $f \n $l"
else
	echo "Name less than 6 char long"
fi
