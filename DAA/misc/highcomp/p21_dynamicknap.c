/*Knapsack problem using dynamic programming*/
#include<stdio.h>
#include<stdlib.h>
int Values[15], Weights[15];
int W, n;
int V[15][15];
int max(int i, int k) {
    if (i > k) return i;
    else return k;
}
int Knapsack() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= W; j++) {
            if (j - Weights[i] < 0) {
                V[i][j] = V[i - 1][j];
            } else {
                V[i][j] = max(V[i - 1][j], Values[i] + V[i - 1][j - Weights[i]]);
            }
        }
    }
    return V[n][W];
}
int main() {
    int i, j, val;
    // clrscr();
    printf("Enter no of items\n");
    scanf("%d", & n);
    printf("Enter the capacity of knapsack\n");
    scanf("%d", & W);
    printf("Enter the weight and value of each item\n");
    for (i = 1; i <= n; i++) {
        printf("\nItem No: %d ->", i);
        printf("Weight: ");
        scanf("%d", & Weights[i]);
        printf("Value: ");
        scanf("%d", & Values[i]);
    }
    for (i = 0; i <= n; i++)
        V[i][0] = 0; //initialize first rowfor(j=0;j<=W;j++)
    V[0][j] = 0; //initialize first column
    val = Knapsack();
    printf("The Knapsack table %d\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            printf("%d\t", V[i][j]);
        }
        printf("\n");
    }
    printf("The optimal value is \n", val);
    printf("The items added are:\n");
    for (i = n, j = W; i > 0; i--) {
        if (V[i][j] != V[i - 1][j]) {
            printf("%d\t", i);
            j = j - Weights[i];
        }
    }
    return 0;
}