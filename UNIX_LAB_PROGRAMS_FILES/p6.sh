#!\bin\sh                                                                    
echo "enter the string"                  
read string
if [ -z "$string" ]
then 
echo "null string"
else
z=`expr "$string" : '.*'`
echo "string length is $z"
fi
if [ $z -ge 6 ]
then
echo "first 3 characters"
z=`expr "$string" : '\(...\).*'`
echo "$z"
echo "last 3 characters"
x=`expr "$string" : '.*\(...\)'`
echo "$x"
fi
#OR:
