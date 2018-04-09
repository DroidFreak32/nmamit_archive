#include<stdio.h>
#include<stdlib.h>
int randomize(int a)
{
	int rn=(rand()%10)%a;
	return rn==0?1:rn;
}

int main()
{
	int packet_sz[5],i,clk,b_size,o_rate,p_sz_rm=0,p_sz,p_time;
	for(i=0;i<5;++i)
		packet_sz[i]=randomize(6)*10;
	for(i=0;i<5;++i)
		printf("packet[%d]:%d bytes\t",i,packet_sz[i]);
	printf("\nEnter the Output rate:");
	scanf("%d",&o_rate);
	printf("Enter the Bucket Size:");
	scanf("%d",&b_size);
	for(i=0; i<5; ++i)
	{
		if((packet_sz[i]+p_sz_rm) > b_size)
			if(packet_sz[i] > b_size)
				printf("\n\nIncomming packet size (%d) is Greater than bucket capacity-PACKET REJECTED",packet_sz[i]);
			else
				printf("\n\nBucket capacity exceeded-REJECTED!!");
		else
		{
			p_sz_rm+=packet_sz[i];
			printf("\n\nIncomming Packet size: %d",packet_sz[i]);
			printf("\nBytes remaining to Transmit: %d",p_sz_rm);
			p_time = randomize(4)*10;
			printf("\nTime left for transmission: %d units",p_time);
			for(clk=10; clk<=p_time; clk+=10)
			{
				sleep(1);
				if(p_sz_rm)
				{
					if(p_sz_rm <= o_rate)
						printf("\n  Packet of size %d Transmitted",p_sz_rm),
							p_sz_rm=0;
					else
						printf("\n  Packet of size %d Transmitted",o_rate),
							p_sz_rm -= o_rate;
					printf("----Bytes Remaining after Transmission: %d",p_sz_rm);
				}
				else
					printf("\n  No packets to transmit!!");
				printf("   Time Left:%d",p_time-clk);
			}
		}
	}
}
