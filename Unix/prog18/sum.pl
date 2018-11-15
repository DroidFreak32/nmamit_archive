#!/usr/bin/perl
foreach $num(@ARGV)
{
	$n=$num;
	until($num==0)
	{
		$digit=$num%10;
		$sum=$sum+$digit;
		$num=int($num/10);
	}
	print("Sum of the digits of $n = $sum\n");
	$sum=0;
}
