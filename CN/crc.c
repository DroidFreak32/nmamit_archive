#include<stdio.h>
int input[50];
int n;
struct reg
{
	int bit;
}r[16];

int xor(int x,int y)
{
	x+=y;
	if(x==0 || x==2)
		return 0;
}

void compcrc()
{
	int lb,x,j,i;
	for(j=0;j<(n+16);j++)
	{
		lb=r[15].bit;
		for(i=15;i>0;i--)
		{
			r[i].bit=r[i-1].bit;
		}
		r[0].bit=input[j];
		if(lb==1)
		{

			r[12].bit=xor(r[12].bit,lb);
			r[5].bit=xor(r[5].bit,lb);
			r[0].bit=xor(r[0].bit,lb);
		}
	}
	printf("Register content:\n");
	for(i=0;i<16;i++)
		printf("%d",r[i].bit);
	printf("\n");
	for(x=n,j=15;j>=0;x++,j--)
		input[x]=r[j].bit;
	printf("\nThe total message along with crc :\n");
	for(i=0;i<(n+16);i++)
		printf("%d",input[i]);
}

int  main()
{
	int i,j,k,x,y;
	for(i=0;i<16;i++)
		r[i].bit=0;
	printf("\nEnter the number of bits in the input:\n");
	scanf("%d",&n);
	printf("\nEnter the bits:\n");
	for(k=0;k<n;k++)
		scanf("%d",&input[k]);
	for(j=n;j<(n+16);j++)
		input[j]=0;
	printf("\nAt sender:\n");
	compcrc();
	for(i=0;i<16;i++)
		r[i].bit=0;
	printf("\nThe data is transmitted\n");
	printf("Do you want to introduce error : 0/1 \n");
	scanf("%d",&x);
	printf("=====*************=====\n");
	if(x==1)
	{
		for(i=0;i<n+16;i++)
			scanf("%d",&input[i]);
	}
	printf("\nAt receiver:\n");
	compcrc();
	if(x==1)
	{
		printf("\nThere is an error in the data\n");
		printf("\nThe received data : ");
		for(i=0;i<n;i++)
			printf("%d",input[i]);
	}
	else
	{
		printf("\nThere is no error in the data.\n");
		printf("\nThe received data : ");
		for(i=0;i<n;i++)
			printf("%d",input[i]);
	}
	printf("\n");
}
