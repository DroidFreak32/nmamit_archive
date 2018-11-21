#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>
void bsort(int a[100], int n);
struct timeval tim;
double dtime1, dtime2;
int main()
{
    int a[100], n, i, v;
    printf("Enter the values of n:");
    scanf("%d", &n);
    for (v = 0; v < n; v++)
        a[v] = rand() % 100;
    printf("\nElements entered: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    bsort(a, n);
    printf("\nElements after sorting\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\nElapsed time is %lf\n", dtime2 - dtime1);
    return 0;
}

void bsort(int a[100], int n)
{
    int i, temp, j;
    gettimeofday(&tim, NULL);
    dtime1 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    for (i = 0; i < n; i++)
        for (j = 0; j < n - 1; j++)
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
    gettimeofday(&tim, NULL);
    dtime2 = tim.tv_sec + (tim.tv_usec / 1000000.0);

}
