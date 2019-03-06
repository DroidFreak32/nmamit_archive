BEGIN{
	count=0;
}
{
	event = $1;
	if (event == "d") { count++; }
}
END{
	printf("No of dropped packets : %d\n",count);
}