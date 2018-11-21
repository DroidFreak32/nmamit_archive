#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
struct timeval tim;
double dtime1, dtime2;
int order[10], A[10][10], n, indegree[10], visited[10], e, k = 0;
int is_all_nodes_visited()
{
    int i;
    for (i = 1; i <= n; i++) {
        if (visited[i] == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int i, j, v1, v2, w;;
    printf("Enter no of vertices of the graph\n");
    scanf("%d", &n);
    printf("Enter the number of edges of the graph:\n");
    scanf("%d", &e);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            A[i][j] = 0;
        }
    }
    for (i = 1; i <= n; i++) {
        indegree[i] = 0;
    }
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
    }
    printf("Enter the edges of the graph one by one:\n");
    for (i = 1; i <= e; i++) {
        scanf("%d %d", &v1, &v2);
        A[v1][v2] = 1;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (A[i][j] == 1)
                indegree[j] = indegree[j] + 1;
        }
    }
    gettimeofday(&tim, NULL);
    dtime1 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    while (1) {
        if (is_all_nodes_visited())
            break;
        else
            for (i = 1; i <= n; i++) {
                if (indegree[i] == 0 && visited[i] == 0) {
                    order[k] = i;
                    k++;
                    visited[i] = 1;
                    for (w = 1; w <= n; w++) {
                        if (A[i][w] == 1 && visited[w] == 0) {
                            indegree[w]--;
                        }
                    }
                }
            }
    }
    printf("The Topological ordering is:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", order[i]);
    }
    gettimeofday(&tim, NULL);
    dtime2 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    printf("\n Elapsed time is %lf second\n", dtime2 - dtime1);
    return 0;
}
