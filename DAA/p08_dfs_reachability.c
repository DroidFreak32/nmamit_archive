#include <stdio.h>
int A[20][20], visited[20], count = 0, n;
void dfs(int v)
{
    int w;
    count = count + 1;
    visited[v] = count;
    printf("%d  \n", v);
    for (w = 1; w <= n; w++) {
        if (A[v][w] && visited[w] == 0) {
            dfs(w);
        }
    }
}

int main()
{
    int i, j, v1, v2, s, e;
    printf("Enter the number of vertices of the graph:\n");
    scanf("%d", &n);
    printf("Enter the number of edges of the graph:\n");
    scanf("%d", &e);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            A[i][j] = 0;
        }
    }
    printf("Enter the edges of the graph one by one:\n");
    for (i = 1; i <= e; i++) {
        scanf("%d %d", &v1, &v2);
        A[v1][v2] = A[v2][v1] = 1;      //undirected graph
        //A[v1][v2]=1//directed graph
    }
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
    }
    printf("Enter the vertex:\n");
    scanf("%d", &s);
    printf("Adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%d\t", A[i][j]);
        printf("\n");
    }
    printf("The vertices reachable from %d are:\n", s);
    dfs(s);
    // getch();
    return 0;
}
