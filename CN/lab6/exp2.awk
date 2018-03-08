BEGIN {
	ctcp = 0;
	cudp =0;
}
{
	pkt = $5;
	if(pkt == "cbr") {cudp++;} 
	if(pkt == "tcp") {ctcp++;} 
}
END{
	printf("\nNo of pkts sent\nTCP: %d\nUDP: %d\n",cudp,ctcp);
}