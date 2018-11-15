#!/usr/bin/perl
@dept_arr=<>;
for($i=0;$i<3;$i++)
{
print("Enter the code to look up");
chop($code=<STDIN>);
@found_arr=grep(/^$code/,@dept_arr);
if($#found_arr==-1 || $code eq "\n")
{
print("Code not found");
next;
}
($code,$desc)=split(/\|/,$found_arr[0]);
print("CODE=$code  DESCRIPTION=$desc");
}

