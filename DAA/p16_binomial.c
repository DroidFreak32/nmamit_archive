#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
struct timeval tim;
double dtime1, dtime2;
int c[10][10];
void bin(int n, int k)
{
    int m, i, j;
    for (i = 0; i <= n; i++) {
        m = (i < k ? i : k);
        for (j = 0; j <= m; j++) {
            if (j == 0 || j == i)
                c[i][j] = 1;
            else
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
}

int main()
{
    int m, n, i, j, k;
    printf("\n enter the value of n and k \n");
    scanf("%d%d", &n, &k);
    gettimeofday(&tim, NULL);
    dtime1 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    bin(n, k);
    for (i = 0; i <= n; i++) {
        m = (i < k ? i : k);
        for (j = 0; j <= m; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
    printf("\n Value of %dC%d=%d \n", n, k, c[n][k]);
    gettimeofday(&tim, NULL);
    dtime2 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    printf("\n Elapsed time is %lf second\n", dtime2 - dtime1);
    return 0;
}
