#!/usr/bin/perl
foreach $num(@ARGV)
{
	$temp=$num;
	until($num==0)
	{
		$bit=$num%2;
		unshift(@bit_arr,$bit);
		$num=int($num/2);
	}
	$binary_num=join(" ",@bit_arr);
	print("Binary form of $temp = $binary_num\n");
	$#bit_arr=-1;
}
