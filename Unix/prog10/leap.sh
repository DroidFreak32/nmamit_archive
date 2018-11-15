if [ $# -eq 0 ]; then
	echo "Enter the year"
	read year
else
	year=$1
fi

x=`expr $year % 400`
y=`expr $year % 100`
z=`expr $year % 4`

if [ $x -eq 0 ] || [ $y -ne 0 ] && [ $z -eq 0 ]; then
	echo "It is a leap year"
else
	echo "Not a leap year"
fi

