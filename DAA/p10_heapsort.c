#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
void heapy(int a[], int n)
{
    int i, k, v, heap, j;
    for (i = (n / 2); i >= 1; i--) {
        k = i;
        v = a[k];
        heap = 0;
        while (!heap && 2 * k <= n) {
            j = 2 * k;
            if (j < n) {
                if (a[j] < a[j + 1])
                    j++;
            }
            if (v >= a[j])
                heap = 1;
            else {
                a[k] = a[j];
                k = j;
            }
        }
        a[k] = v;
    }
}

void maximumkey(int a[], int n)
{
    int temp;
    temp = a[1];
    a[1] = a[n];
    a[n] = temp;
    n = n - 1;
    heapy(a, n);
    if (n >= 1)
        maximumkey(a, n);
}

int main()
{
    struct timeval tim;
    double d1, d2;
    int a[100], n, i;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("\nEnter the numbers: ");
    for (i = 1; i <= n; i++)
        a[i] = rand() % 50;
    printf("\nThe numbers are:\n");
    for (i = 1; i <= n; i++)
        printf("%d\t", a[i]);
    gettimeofday(&tim, NULL);
    d1 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    heapy(a, n);
    printf("\nThe heap tree is:\n");
    for (i = 1; i <= n; i++)
        printf("%d\t", a[i]);
    maximumkey(a, n);
    gettimeofday(&tim, NULL);
    d2 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    printf("\nThe sorted array:\n");
    for (i = 1; i <= n; i++)
        printf("%d\t", a[i]);
    printf("\nExecution Time: %lf", d2 - d1);
    return 0;
}
