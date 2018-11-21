#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <sys/time.h>

int a[20], n, count[20], s[20];

void comparison_sort()
{
    int i, j;
    for (i = 0; i < n; i++)
        count[i] = 0;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++) {
            if (a[i] < a[j])
                count[j]++;
            else
                count[i]++;
        }
    for (i = 0; i < n; i++)
        s[count[i]] = a[i];
}

int main()
{
    int i;
    struct timeval tim;
    double dtime1, dtime2;
    printf("\nEnter the number of elements:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        a[i] = rand() % 100;
    printf("\nThe Array:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    gettimeofday(&tim, NULL);
    dtime1 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    comparison_sort();
    gettimeofday(&tim, NULL);
    dtime1 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    printf("\nThe Sorted Array:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", s[i]);
    printf("\nElapsed time:%f seconds", dtime2 - dtime1);
}
