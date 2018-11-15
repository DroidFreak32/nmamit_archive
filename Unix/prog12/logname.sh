if [ $# -eq 0 ]; then
	echo "no arguements"
exit
fi
for lognme in "$@"
do	usr=`grep -w "^$lognme" /etc/passwd`
	if [ -z $usr ]; then
		echo "$lognme is an invalid loginname"
	else
#		uname=`echo $usr|cut -d ":" -f 1`
		home=`echo $usr|cut -d ':' -f 6`
		echo "Login name: $lognme\nHome directory: $home"
	fi
done

