#include <stdio.h>
    int q[50], front = 1, rear = 0, n, count = 0, i, j, A[20][20], visited[20];
void bfs(int v) {
    int q[50], front = 1, rear = 0, w;
    count = count + 1;
    visited[v] = count;
    printf("%d is visited\n", v);
    q[++rear] = v; //insert v to queue
    while (front <= rear) {
        v = q[front];
        for (w = 1; w <= n; w++) {
            if (visited[w] == 0 && A[v][w] == 1) {
                count++;
                visited[w] = count;
                printf("%d is visited\n", w);
                q[++rear] = w;
            }
        }
        front++;
    }
}
int main() {
    int v1, v2, e, k;
    printf("Enter the number of vertices of the graph\n");
    scanf("%d", & n);
    printf("Enter the number of edges of the graph:\n");
    scanf("%d", & e);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            A[i][j] = 0;
        }
    }
    printf("Enter the edges of the graph one by one:\n");
    for (i = 1; i <= e; i++) {
        scanf("%d %d", & v1, & v2);
        A[v1][v2] = A[v2][v1] = 1; //undirected graph
        //A[v1][v2]=1//directed graph
    }
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
    }
    for (k = 1; k <= n; k++) {
        if (visited[k] == 0)
            bfs(k);
    }
    return 0;
}