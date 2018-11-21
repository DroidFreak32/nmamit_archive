#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
int partition(int a[], int l, int r)
{
    int p, i, j, temp;
    p = a[l];
    i = l;
    j = r + 1;
    do {
        do {
            i = i + 1;
        } while (a[i] < p && i <= r);
        do {
            j = j - 1;
        } while (a[j] > p);
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    } while (i < j);
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j;
}

void quick(int a[], int l, int r)
{
    int s;
    if (l < r) {
        s = partition(a, l, r);
        quick(a, l, s - 1);
        quick(a, s + 1, r);
    }
}

int main()
{
    int i, n, a[1000];
    struct timeval tim;
    double dtim1, dtim2;
    printf("Enter the number of Elements\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        a[i] = rand() % 50;
    printf("Array Elements are\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    gettimeofday(&tim, NULL);
    dtim1 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    quick(a, 0, n - 1);
    gettimeofday(&tim, NULL);
    dtim2 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    printf("\nThe Sorted array is\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\nElapsed time is %lf seconds\n", dtim2 - dtim1);
    return 0;
}
