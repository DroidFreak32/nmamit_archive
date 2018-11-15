f1=$1
f2=$2
set -- `ls -l $f1`
a=$1
set -- `ls -l $f2`
b=$1
echo "$a \n $b \n"
if [ $a = $b ]; then
	echo "same"
else
	echo "$f1 = $a and \n$f2 = $b"
fi