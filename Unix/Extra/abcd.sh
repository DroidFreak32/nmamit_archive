if [ $# -eq 0 ]
then
 echo " enter file names "
read file1
read file2
else 
file1=$1
file2=$2
fi
set -- ` ls -l $file1 `
p1=$1
set -- ` ls -l $file2 `
p2=$1
if [ $p1 = $p2 ]
then
 echo " common permission "
else
 echo " no commom permission "
 echo " $file1 :$p1 "
 echo " $file2 :$p2 "
fi
