#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[40], n, temp, i, j, pos;
    printf("enter the value of n:");
    scanf("%d", &n);
    printf("enter the numbers");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n - 1; i++) {
        temp = a[i];
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (temp < a[j]);
            {
                temp = a[j];
                pos = j;
            }

        }
        a[pos] = a[i];
        a[i] = temp;
    }
    printf("the elements are ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
