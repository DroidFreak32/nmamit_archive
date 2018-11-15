#!/usr/bin/perl
@dept_arr=<>;
for($i=0;$i<3;$i++)
{
print(“enter code to lookup”);
chop($code=<STDIN>);
@found_arr=grep(/^$code/,@dept_arr);
if($#found_arr==-1||code eq “ “)
{
print(“code not found\n”);
next;
}
($code,$desc)=split(/\|/,$found_arr[0]);
print(“code=$code description=$_[1]\n”);
}