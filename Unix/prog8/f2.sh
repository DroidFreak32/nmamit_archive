if [ $# -eq 0 ]
then
	echo "Enter pattern: "
	read pat
	echo "Enter filename"
	read file
else
	pat=$1
	file=$2
fi
sh f1.sh $pat $file


