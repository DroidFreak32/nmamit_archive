if [ $# -eq 0 ]
then
read f1
read f2
else
f1=$1
f2=$2
fi
set -- `ls -l $f1`
a=$1
set -- `ls -l $f2`
b=$1
if [ $a = $b ]
then echo $f1" and "$f2" have common permission: "$b
else echo $f1" and "$f2" do not have common permission. Permissions are $a and $b"
fi
