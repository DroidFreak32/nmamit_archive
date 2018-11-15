#!/usr/bin/perl
Foreach $number (@ARGV)
{
$original_number=$number;
until($number==0)
{
$bit=$number%2;
Unshift(@bit_arr,$bit);
$number=int($number/2);
}
$binary_number=join(“”,@bit_arr);
Print(“binary number of $original_number is $binary_number\n”)
$#bit_arr=-1;
}