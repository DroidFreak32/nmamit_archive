mkdir -p $1
a=`echo $1|tr '/' ' '`
for dirs in $a
do 
	echo "$dirs exists in `pwd`"
	cd `pwd`/$dirs
done
