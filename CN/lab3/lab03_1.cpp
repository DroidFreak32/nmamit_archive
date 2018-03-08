#include <stdio.h>
#define INFINITY 999

struct node{
    int cost;
    int via;
} c[4][4];
int n;

void findpath(int n1, int n2){
    int i,t1,t2;
    t1=c[n1][n2].via;
    if(t1 < n2)
        findpath(n1,t1);
    if(t1!=n2)
        printf("%d-->",t1);
}

void matrix(){
    int i,j,k,cost,x,t;
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
        {
            cost=INFINITY;
            if(i != j){
                for (k = 0; k < n; k++)
                    if (i != k)
                    {
                        x = c[i][k].cost+c[k][j].cost;
                        if (cost > x){
                            cost=x;
                            t=k;
                        }
                    }
                c[i][j].cost = cost;
                c[i][j].via = t;
            }
            else{
                c[i][j].cost=0;
                c[i][j].via=i;
            }
        }
}


int main(){
    int i,j,k,x,t,cost=INFINITY;
    int n1,n2,final,t1,t2,next;
    printf("Enter the Number of nodes: \n");
    scanf("%d",&n);
    printf("\nEnter the edge matrix, 999 if no direct connection. \n");

    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
        {
            printf("cost[%d][%d] = ",i,j);
            scanf("%d",&c[i][j].cost);
            c[i][j].via=INFINITY;
        }

    printf("\nStarting matrix (each entry has cost via node):\n");

    for (i = 0; i < n; ++i)
    {
        printf("row %d\t",i);
        for (j=0; j<n; j++)
            printf("%d,%d\t",c[i][j].cost,c[i][j].via);
        printf("\n");
    }

    matrix();

    printf("Final matrix\n");
    for (i = 0; i < n; ++i)
    {
        printf("row %d\t",i);
        for (j=0; j<n; j++)
            printf("%d,%d\t",c[i][j].cost,c[i][j].via);
        printf("\n");
    }

    next=1;
    while (next){
        printf("Enter 2 node numbers to  find the path\n");
        printf("Enter source node:\n");
        scanf("%d",&n1);
        printf("\nEnter destination node:\n");
        scanf("%d",&n2);
        printf("\nThe shortest path to reach %d from %d has cost = %d\n", n2,n1,c[n1][n2].cost);
        printf("The path is\n");
        final = c[n1][n2].via;

        printf("%d -->", n1);
        findpath(n1,n2);
        printf("%d",n2 );
        printf("\nWould you like to continue (0/1) \n");
        scanf("%d",&next);
    }
}