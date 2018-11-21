#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
int i, n, j, temp, a[20];
int main()
{
    struct timeval tim;
    double dtime1, dtime2;
    printf("Enter the no of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        a[i] = rand() % 100;
    printf("\nArray elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    gettimeofday(&tim, NULL);
    dtime1 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    insertion();
    gettimeofday(&tim, NULL);
    dtime2 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    printf("\nArray after sorting: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nElapsed time: %f seconds", dtime2 - dtime1);
}

void insertion()
{
    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;
        while (temp < a[j] && (j >= 0)) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
}
