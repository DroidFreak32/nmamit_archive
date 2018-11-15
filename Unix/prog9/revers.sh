if [ $# -eq 0 ]; then
	echo "Enter arguements"	
else
	echo "Entered arguements: $*"
	for i in "$@"
	do
		j=$i" "$j
	done
	echo "Reversed: "$j
fi
