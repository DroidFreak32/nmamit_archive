#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>
int A[20][20],visited[20],count=0,n,order[10],k=0;
void dfs(int v)
{
    int w;
    count=count+1;
    visited[v]=count;
    for(w=1;w<=n;w++)
    {
        if(A[v][w] && visited[w]==0)
        {
            dfs(w);                     //8055//

        }
    }
    order[k]=v;
    k++;
}
int main()
{
	struct timeval tim;
    double d1,d2;
    int i,j,k,v1,v2,e;
    printf("Enter no of vertices : ");
    scanf("%d",&n);
    printf("Enter no of edges:");
    scanf("%d",&e);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            A[i][j]=0;
        }
    }
    printf("Enter the edges of the graph one by one:\n");
    for(i=1;i<=e;i++)
    {
        scanf("%d %d",&v1,&v2);
        A[v1][v2]=1;

    }
	gettimeofday(&tim,NULL);
    d1=tim.tv_sec+(tim.tv_usec/1000000.0);
    for(i=1;i<=n;i++)
    {
        visited[i]=0;

    }
    for(k=1;k<=n;k++)
    {
        if(visited[k]==0)
        dfs(k);

    }
	gettimeofday(&tim,NULL);
    d1=tim.tv_sec+(tim.tv_usec/1000000.0);
    printf("The topological ordering is:\n");
    for(i=n-1;i>=0;i--)
    {
        printf("%d\t",order[i]);
    }
    printf("\nAdjacency matrix:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%d\t",A[i][j]);
        printf("\n");
    }
    printf("\nEkecution Time: %lf",d2-d1);
    return 0;
}

