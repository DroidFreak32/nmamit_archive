#include <stdio.h>
#include <sys/time.h>

int a[10][10],b[10][10];
int n,e;
int root[10];


void update(int v1,int v2)
{
    int i,t;
    t=root[v2];
    for(i=1;i<=n;i++)
        if(root[i]==t)
            root[i]=root[v1];
}

void findmin(int *v1,int *v2)
{
    int edge=0,i,j;
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
                    if((edge>a[i][j]||edge==0)&&a[i][j]>0)
                    {
                        edge=a[i][j];
                        *v1=i;
                        *v2=j;
                    }


}

int kruskals()
{
    int i,j,v1,v2,cost,ecounter=0,tcost=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            {
                if(i==j)
                    b[i][j]=0;
                else
                    b[i][j]=999;
            }
    while(ecounter<(n-1))
    {
        findmin(&v1,&v2);
        cost=a[v1][v2];
        a[v1][v2]=a[v2][v1]=0;
        if(root[v1]!=root[v2])
        {
            b[v1][v2]=b[v2][v1]=cost;
            update(v1,v2);
            tcost+=cost;
            ecounter++;
        }
    }
    return tcost;
}

void main()
{
    int v1,v2,i,j,cost;
    struct timeval tim;
    double dtime1,dtime2;
    printf("\nEnter the number of vertices:");
    scanf("%d",&n);
    printf("\nEnter the number of edges:");
    scanf("%d",&e);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            {
                if(i==j)
                    a[i][j]=0;
                else
                    a[i][j]=999;
            }
    printf("\nEnter the edges:");
    for(i=0;i<e;i++)
    {
        printf("\nEnd vertex v1:");
        scanf("%d",&v1);
        printf("\nEnd vertex v2:");
        scanf("%d",&v2);
        printf("\nEnter weight:");
        scanf("%d",&cost);
        a[v1][v2]=a[v2][v1]=cost;
    }
    for(i=1;i<=n;i++)
        root[i]=i;
    printf("\nThe given graph is:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
    gettimeofday(&tim,NULL);
    dtime1=tim.tv_sec+(tim.tv_usec/1000000.0);
    cost=kruskals();
    gettimeofday(&tim,NULL);
    dtime2=tim.tv_sec+(tim.tv_usec/1000000.0);
    printf("\nThe minimum spanning tree is:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d\t",b[i][j]);
        printf("\n");
    }
    printf("\n\nThe total cost is:%d",cost);
    printf("\nElapsed time:%f seconds",dtime2-dtime1);
}
