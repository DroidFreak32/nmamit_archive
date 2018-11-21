#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>
int a[50][50];
int visited[50];
int e,v1,v2,i,j,k;
int v,r;
struct timeval tim;
double dtime1,dtime2;
void dfs(int k){
    int w,count=0;
    count=count+1;
    visited[k]=count;
    static int h=1;
    printf("\n v %d is :",h);
    h++;
    printf("%d",k);
    for(w=1;w<=r;w++){
        if(a[k][w]==1 && visited[w]==0)
            dfs(w);
    }
}
int main(){
    printf("Enter number of vertices:");
    scanf("%d",&r);
    printf("Enter number of edges:");
    scanf("%d",&e);
//    for(i=0;i<r;i++)
//        for(j=0;j<r;j++)
//            a[i][j]=0;
    for(i=0;i<e;i++){
        printf("Enter vertex %d and vertex%d:",i+1,i+2);
        scanf("%d%d",&v1,&v2);
        a[v1][v2]=a[v2][v1]=1;
    }
    printf("Adjacency matrix:\n");
    for(i=1;i<=r;i++){
        for(j=1;j<=r;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
    gettimeofday(&tim,NULL);
    dtime1=tim.tv_sec+(tim.tv_usec/1000000.0);
    for(i=0;i<50;i++)
        visited[i]=0;
    for(k=1;k<=r;k++)
        if(visited[k]==0)
            dfs(k);
    gettimeofday(&tim,NULL);
    dtime2=tim.tv_sec+(tim.tv_usec/1000000.0);
    printf("\nElapsed time is %f:",dtime2-dtime1);
    return 0;
}
