#!/bin/sh
display_perm()
{
	r=`ls -l $1 | cut -c 2`
	w=`ls -l $1 | cut -c 3`
	x=`ls -l $1 | cut -c 4`
	echo "Owner permissions"
	if [ "$r" = "r" ]
	then
		echo "Read"
	else
		echo "No Read"
	fi
	if [ "$w" = "w" ]
        then
                echo "Write"
        else
                echo "No Write"
        fi
	if [ "$x" = "x" ]
        then
                echo "Execute"
        else
                echo "No Execute"
        fi
	r=`ls -l $1 | cut -c 5`
        w=`ls -l $1 | cut -c 6`
        x=`ls -l $1 | cut -c 7`
        echo "Group permissions"
        if [ "$r" = "r" ]
        then
                echo "Read"
        else
                echo "No Read"
        fi
        if [ "$w" = "w" ]
        then
                echo "Write"
        else
                echo "No Write"
        fi
        if [ "$x" = "x" ]
        then
                echo "Execute"
        else
                echo "No Execute"
        fi
	r=`ls -l $1 | cut -c 8`
        w=`ls -l $1 | cut -c 9`
        x=`ls -l $1 | cut -c 10`
        echo "Other permissions"
        if [ "$r" = "r" ]
        then
                echo "Read"
        else
                echo "No Read"
        fi
        if [ "$w" = "w" ]
        then
                echo "Write"
        else
                echo "No Write"
        fi
        if [ "$x" = "x" ]
        then
                echo "Execute"
        else
                echo "No Execute"
        fi
}
echo "Enter two filenames :"
read f1 f2
if [ -e $f1 -a -e $f2 ]
then
	p1=`ls -l $f1 | cut -c 2-10`
	p2=`ls -l $f2 | cut -c 2-10`
	echo "$f1 = $p1"
	echo "$f2 = $p2"
	if [ "$p1" = "$p2" ]
	then
		echo "$f1 and $f2 have the same permission"
		display_perm $f1
	else
		echo "Permissions for $f1"
		display_perm $f1
		echo "Permissions for $f2"
                display_perm $f2
	fi
else
	echo "Invalid permission"
fi
exit
