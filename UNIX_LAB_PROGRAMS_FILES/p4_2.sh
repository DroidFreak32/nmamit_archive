#! /bin/sh
if [ $# -eq 0 ]
then
    echo "Enter the pattern"
    read pattern
    echo "Enter the filename"
    read filename
else
pattern= $1
        filename= $2
fi