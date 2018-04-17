#include<stdio.h> 
#define INFINITY 999 
struct node {
    int cost;
    int via;
}
c[4][4];
int n;
void findpath(int n1, int n2) {
    int i, t1, t2;
    t1 = c[n1][n2].via;
    if (t1 < n2)
        findpath(n1, t1);
    if (t1 != n2)
        printf("%d-->", t1);
}
void matrix() {
    int i, j, k, cost, x, t;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cost = INFINITY;
            if (i != j) {
                for (k = 0; k < n; k++) {
                    if (i != k) {
                        x = c[i][k].cost + c[k][j].cost;
                        if (cost > x) {
                            cost = x;
                            t = k;
                        }
                    }
                }
                c[i][j].cost = cost;
                c[i][j].via = t;
            } else {
                c[i][i].cost = 0;
                c[i][i].via = i;
            }
        }
    }
}
int main() {
    int i, j, k, x, t, cost = INFINITY;
    int n1, n2, final, t1, t2, next;
    printf("Enter the number of nodes:");
    scanf("%d", & n);
    printf("Enter the edge matrix(enter 999 if nodirect connection)\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("cost[%d][%d]=", i, j);
            scanf("%d", & c[i][j].cost);
            c[i][j].via = INFINITY;
        }
    }
    printf("starting matrix:(Each entry has cost and via node\n");
    for (i = 0; i < n; i++) {
        printf("row %d\t", i);
        for (j = 0; j < n; j++) {
            printf("%d,%d\t", c[i][j].cost, c[i][j].via);
        }
        printf("\n");
    }
    matrix();
    printf("final matrix\n");
    for (i = 0; i < n; i++) {
        printf("row %d\t", i);
        for (j = 0; j < n; j++) {
            printf("%d,%d\t", c[i][j].cost, c[i][j].via);
        }
        printf("\n");
    }
    next = 1;
    while (next) {
        printf("Enter the two node numbers to find the path\n");
        printf("Enter the source node:");
        scanf("%d", & n1);
        printf("Enter the destination node:");
        scanf("%d", & n2);
        printf("The shortest path to reach %d from %d has cost =%d\n", n2, n1, c[n1][n2].cost);
        printf("The path is:\n");
        final = c[n1][n2].via;
        printf("%d-->", n1);
        findpath(n1, n2);
        printf("%d", n2);
        printf("would you like to continue (0/1)");
        scanf("%d", & next);
    }
}