#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

int w[100][100],d[100][100],n;

void floyd()
{
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            d[i][j]=w[i][j];
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                d[i][j]=fmin(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    printf("Distance matrix of the shortest paths length \n");
     for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d \t",d[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    struct timeval tim;
    double t1,t2;
    int i,j;
    printf("Enter the size of weight matrix of the graph\n");
    scanf("%d",&n);
    //n=4;
    printf("Enter the weight matrix of a graph \n");
     for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&w[i][j]);
        }
    }
    gettimeofday(&tim,NULL);
    t1=tim.tv_sec+(tim.tv_usec/1000000.0);
    floyd();
    gettimeofday(&tim,NULL);
    t2=tim.tv_sec+(tim.tv_usec/1000000.0);
    printf("Elapsed time is %lf s",t2-t1);
    return 0;
}
