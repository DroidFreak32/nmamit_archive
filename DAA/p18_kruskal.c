/* Kruskal's algorithm to find minimum spanning tree */
#include<stdio.h>
int A[10][10], B[10][10];       //A-given graph; B - Minimum Spanning Tree
int n, e;
int root[10];
void update(int v1, int v2)
{
    int i, t;
    t = root[v2];
    for (i = 1; i <= n; i++) {
        if (root[i] == t)
            root[i] = root[v1];
    }
}

void FindMin(int *v1, int *v2)
{
    int edge = 0, i, j;
    for (i = 1; i <= n; i++)
        for (j = i + 1; j <= n; j++) {
            if ((edge > A[i][j] || edge == 0) && A[i][j] > 0) {
                edge = A[i][j];
                *v1 = i;
                *v2 = j;
            }
        }
}

int Kruskals()
{
    int i, j, ecounter = 0;
    int v1, v2;
    int cost;
    int total_cost = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            if (i == j)
                B[i][j] = 0;
            else
                B[i][j] = 999;
        }
    //initialization of adjacency matrix
    while (ecounter < (n - 1)) {
        FindMin(&v1, &v2);
        cost = A[v1][v2];
        A[v1][v2] = A[v2][v1] = 0;
        if (root[v1] != root[v2]) {
            B[v1][v2] = B[v2][v1] = cost;
            update(v1, v2);
            total_cost = total_cost + cost;
            ecounter++;
        }
    }
    return total_cost;
}

int main()
{
    int v1, v2;
    int i, j, cost;
    //clrscr();
    printf("Enter no of vertices\n");
    scanf("%d", &n);
    printf("Enter no of edges\n");
    scanf("%d", &e);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            if (i == j)
                A[i][j] = 0;
            else
                A[i][j] = 999;
        }
    //initialization of adjacency matrix
    printf("Enter the Edges one by one\n");
    for (i = 1; i <= e; i++) {
        printf("Edge %d: ", i);
        scanf("%d%d", &v1, &v2);
        printf("Weight: ");
        scanf("%d", &cost);
        A[v1][v2] = A[v2][v1] = cost;
    }
    for (i = 1; i <= n; i++) {
        root[i] = i;
    }
    printf("The given graph is:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%d\t", A[i][j]);
        printf("\n");
    }
    cost = Kruskals();
    printf("The minimum spanning tree for the given graph is:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%d\t", B[i][j]);
        printf("\n");
    }
    printf("\nThe total cost is: %d", cost);
}
