#include <stdio.h>
#include <math.h>
#include <sys/time.h>

int place(int k,int a[])
{
    int i;
    for(i=1;i<k;i++)
        if(a[i]==a[k]||(abs(i-k)==abs(a[i]-a[k])))
            return 0;
    return 1;
}

void nqueen(int n)
{
    int k=1;
    int i, count=0;
    int a[10];
    a[k]=0;
    while(k!=0)
    {
        a[k]++;
        while((a[k]<=n)&&(place(k,a)==0))
            a[k]++;
        if(a[k]<=n)
        {
            if(k==n)
            {
                count++;
                printf("\nSolution number:%d\n",count);
                for(i=1;i<=n;i++)
                    printf("\nQueen %d is places in Row %d and Column %d",i,i,a[i]);
            }
            else
            {
                k++;
                a[k]=0;
            }
        }
        else
            k--;
    }
}

void main()
{
    int n;
    struct timeval tim;
    double dtime1,dtime2;
    printf("\nEnter the nuber of queens:");
    scanf("%d",&n);
    gettimeofday(&tim,NULL);
    dtime1=tim.tv_sec+(tim.tv_usec/1000000.0);
    if(n==2||n==3)
        printf("\nNo solution");
    else
        nqueen(n);
    gettimeofday(&tim,NULL);
    dtime2=tim.tv_sec+(tim.tv_usec/1000000.0);
    printf("\nElapsed time:%f seconds",dtime2-dtime1);
}
