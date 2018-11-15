if [ $# -eq 0 ]; then
	echo "No args provided"
exit
fi
for fname in "$@"
do
if [ -f $fname ]; then
	ufname=`echo $fname | tr '[a-z]' '[A-Z]'`
	if [ -f $ufname ]; then
		echo "$ufname also exists"
	else
		mv $fname $ufname
		echo "$fname is replaced by $ufname"
	fi
	else
	echo "$fname doesnt exist "
fi 
done

