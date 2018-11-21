#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
//void selection();
int patmatch();
int j, i, ind, n, m;
char t[50], p[50];
struct timeval tim;
double dtime1, dtime2;
int main()
{
    printf("Enter the String: ");

    scanf("%s", t);
    printf("\nEntered String: %s", t);
    n = strlen(t);


    printf("\nEnter the Pattern to search: ");
    scanf("%s", p);
    printf("\nEntered Pattern: %s", p);
    m = strlen(p);
    gettimeofday(&tim, NULL);
    dtime1 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    ind = patmatch();
    gettimeofday(&tim, NULL);
    dtime2 = tim.tv_sec + (tim.tv_usec / 1000000.0);
    if (ind == -1)
        printf("\nPattern NOT found");
    else
        printf("\nPattern found at position %d\n", ind);
    printf("\n Elapsed time is %lf\n", dtime2 - dtime1);
    return 0;
}

int patmatch()
{
    for (i = 0; i <= n - m; i++) {
        j = 0;
        while (j < m && p[j] == t[i + j])
            j++;
        if (j == m)
            return i;
    }
    return -1;
}
