#include <stdio.h>
#include <sys/time.h>

int values[15], weights[15], w, n,v[15][15];

int max(int i,int k)
{
    if(i>k)
        return i;
    return k;
}

int mfknapsack(int i,int j)
{
    int value;
    if(v[i][j]<0)
    {
        if(j<weights[i])
            value=mfknapsack(i-1,j);
        else
            value=max(mfknapsack(i-1,j),values[i]+mfknapsack(i-1,j-weights[i]));
        v[i][j]=value;
    }
    return v[i][j];
}

int main()
{
    int i,j,val;
    struct timeval tim;
    double dtime1,dtime2;
    printf("\nEnter the number of items:");
    scanf("%d",&n);
    printf("\nEnter the capacity of knapsack:");
    scanf("%d",&w);
    printf("\nEnter the weight and value of each item:");
    for(i=1;i<=n;i++)
    {
        printf("\nItem number:%d",i);
        printf("\nWeight:");
        scanf("%d",&weights[i]);
        printf("\nValue:");
        scanf("%d",&values[i]);
    }
    for(i=0;i<=n;i++)
        for(j=0;j<=w;j++)
        {
            if(i==0||j==0)
                v[i][j]==0;
            else
                v[i][j]=-1;
        }
    gettimeofday(&tim,NULL);
    dtime1=tim.tv_sec+(tim.tv_usec/1000000.0);
    val=mfknapsack(n,w);
    gettimeofday(&tim,NULL);
    dtime2=tim.tv_sec+(tim.tv_usec/1000000.0);
    printf("\nThe optimal value is:%d",val);
    printf("\nThe items added are:\n");
    for(i=n,j=w;i>0;i--)
        if(v[i][j]!=v[i-1][j])
        {
            printf("%d\t",i);
            j-=weights[i];
        }
    printf("\nElapsed time:%f seconds",dtime2-dtime1);
}
