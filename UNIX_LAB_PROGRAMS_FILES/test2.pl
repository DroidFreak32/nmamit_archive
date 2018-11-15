#!/usr/bin/perl
while(<>)
{
chop;
@field=split(/\|/);
if(1..4)
{
$name=$field[1]; $dept=$field[3];$sal=$field[5];
($fn, $ln)=split(/ /,$name);
$nn=$ln.",".$fn;
$tot+=sal;
printf("%d\t%s\t%s\t%d\n",$.,$nn,$dept,$sal);
}
}
printf("%d",$tot);
