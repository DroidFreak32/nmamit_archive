#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<sys/time.h>
struct timeval tim;
double t1, t2;
int a[100][100], r[100][100], n;

void warshall()
{
    int i, j, k;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            r[i][j] = a[i][j];
        }
    }
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                r[i][j] = r[i][j] || (r[i][k] && r[k][j]);
            }
        }
    }
    printf("The transitive closure is \n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }

}


int main()
{

    //double t1,t2;
    int i, j;
    printf("Enter the order \n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix \n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    gettimeofday(&tim, NULL);
    t1 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    warshall();
    gettimeofday(&tim, NULL);
    t2 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    printf("Elapsed time is %lf s", t2 - t1);
    return 0;
}
