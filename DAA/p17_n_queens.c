/* N - Queens problem using Backtracking */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int place(int k, int a[])
{
    int i;
    for (i = 1; i < k; i++) {
        if ((a[k] == a[i]) || (abs(i - k) == abs(a[i] - a[k])))
            return 0;
    }
    return 1;
}

void nqueen(int n)
{
    int k = 1;
    // queen 1 in row 1
    int i, count = 0;           // count indicates the no of solutions
    int a[10];
    // a[k] holds column no of k th queen
    a[k] = 0;
    //queen 1,in row 1 ,column 0
    while (k != 0) {
        a[k] = a[k] + 1;
        //backtrack till k=1
        //queen k,in next column
        while ((a[k] <= n) && (place(k, a) == 0)) {
            a[k] = a[k] + 1;
        }
        if (a[k] <= n) {
            if (k == n)
                //if we reached last row then print solution
            {
                count++;
                printf("Solution No %d:\n", count);
                for (i = 1; i <= n; i++) {
                    printf
                        ("Queen No: %d is placed in Row No: %d and Column No %d\n",
                         i, i, a[i]);
                }
            } else {
                k++;
                a[k] = 0;
            }
        } else {
            k--;
            //backtrack to previous row
        }
    }
}

int main()
{
    int n, noofsoln;
    printf("Enter the number of queens\n");
    scanf("%d", &n);
    if (n <= 3 && n > 1)
        printf("no solutions\n");
    else
        nqueen(n);
}
