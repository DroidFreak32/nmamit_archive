#!/usr/bin/perl
print "Enter the string:";
$a=<STDIN>;
print "Enter the number of times the string should be displayed:";
chop($b=<STDIN>);
$c=$a x $b;
print "RESULT IS:\n$c";




