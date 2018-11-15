    if [ $# -eq 0 ]
  then
       echo " no arguments "
       exit
  fi
  for lognm in "$@"
  do
       usr=`grep -w "^$lognm"  /etc/passwd`
       if [ -z $usr ]
       then
             echo "$lognm is an invalid login name"
       else
 home=`echo $usr | cut -d ':' -f 6`
 echo "login name is $lognm : home directory is $home"
       fi
  done