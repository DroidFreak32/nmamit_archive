#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
int a[10][10], visited[10], e, n, count = 0;
void dfs(int v)
{
    int w;
    count = count + 1;
    visited[v] = count;
    printf("%d is visited\n", v);
    for (w = 1; w <= n; w++) {
        if (a[v][w] == 1 && visited[w] == 0)
            dfs(w);
    }
}

int main()
{
    struct timeval tim;
    double d1, d2;
    int i, k, j, v1, v2, s, con = 0, flag = 0;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the number of edges\n");
    scanf("%d", &e);
    for (i = 0; i <= n; i++)
        for (j = 0; j <= n; j++)
            a[i][j] = 0;
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    printf("Enter the edges\n");
    for (i = 1; i <= e; i++) {
        scanf("%d%d", &v1, &v2);
        a[v1][v2] = 1;

    }
    printf("Adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
    gettimeofday(&tim, NULL);
    d1 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    for (k = 1; k <= n; k++) {
        flag = 0;
        for (i = 1; i <= n; i++)
            visited[i] = 0;
        dfs(k);
        for (i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            con = con + 1;
        }
    }
    gettimeofday(&tim, NULL);
    d2 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    if (con == n)
        printf("Strongly connected\n");
    else if (con == 0)
        printf("Not connected\n");
    else
        printf("Weakly connected\n");
    printf("\nExecution Time: %lf", d2 - d1);
}
