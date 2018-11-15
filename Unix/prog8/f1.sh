if [ $# -eq 0 ]
then
    echo "No arguements entered"
else
    grep "$1" $2
fi
