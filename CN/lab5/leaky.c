#include<stdio.h>
#include<stdlib.h>
#define BUCKETSIZE 250
#define OUTRATE 25
struct
{
    int arrtime;
    int weight;
} packet[15];
void read_packets(int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("Enter arrival time  :   ");
        scanf("%d",&packet[i].arrtime);
        printf("Enter the packet size   :  ");
        scanf("%d",&packet[i].weight);
    }
}
// leaky bucket algorithm
void lky_bucket()
{
    int excess=BUCKETSIZE;
    int i,j=0,rem=0;
    // receive packets for 30 msec
    for(i=0; i<=30; i++)
    {
        if(packet[j].arrtime==i)
        {
            if(packet[j].weight<=excess)
            {
                rem=packet[j].weight+rem;
                excess=excess-packet[j].weight;
                printf("At Time=%d: Packet %d Inserted into Bucket,",i,j+1);
                printf("\tRemaining Bucket Size= %d\n",excess);
                j=j+1;
            }
            else
            {
                printf("At time = %d: packet %d discarded,",i,j+1);
                printf("\tPacket size is more than buffer size\n");
                j=j+1;
            }
        }
        // send packets every 5 msec
        if((i%5)==0)
        {
            if(rem>=OUTRATE)
            {
                rem=rem-OUTRATE;
                excess=excess+OUTRATE;
                printf("At time = %d : 25 Kbytes are transfered",i);
                printf("\tFree available space in the bucket=%d\n",excess);
            }
            else if(rem>0)
                {
                    excess=excess+rem;
                    printf("At time = %d : %d Kbytes are transferred",i,rem);
                    printf("\tFree available space in the bucket=%d\n",excess);
                    rem=0;
            }
    }
}//for
//Empty the bucket
while(rem != 0)
{
    if(rem < OUTRATE)
    {
        excess=excess+rem;
        printf("At time = %d : %d Kbytes are transfered",i++,rem);
        printf("\tFree available space in the bucket=%d\n",excess);
        break;
    }
    rem=rem-OUTRATE;
    excess=excess + OUTRATE;
    printf("At time = %d : %d Kbytes are transfered",i++,OUTRATE);
    printf("\tFree available space in the bucket=%d\n",excess);
}
printf("Bucket is empty");
}
int main()
{
    int n;
    printf("Enter the number of packets : ");
    scanf("%d",&n);
    read_packets(n);
    lky_bucket();
    return 0;
}

