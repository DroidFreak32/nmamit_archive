#!/usr/bin/perl
@dept_arr=<>;
for($i=0;$i<3;$i++)
{
	print("Enter the code to be searched :");
	chop($code=<STDIN>);
	@found_arr=grep(/^$code/,@dept_arr);
	if(length($code)==0 || code eq "")
	{
		print("Code not found\n");
		next;
	}
	($code,$desc)=split(/\|/,$found_arr[0]);
	print(" Code = $code Description = $desc");
}	
