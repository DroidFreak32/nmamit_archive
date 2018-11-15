{ len=length;
for(i=$0; length(i)>15; len-=15)
{
print substr(i,1,15) "\\"
i=substr(i,16,len);
}
print i; }