/*Knapsack problem using memory functions - dynamic programming*/
#include<stdio.h>
#include<stdlib.h>
int Values[15], Weights[15];
int W, n;
int V[15][15];
int max(int i, int k) {
    if (i > k) return i;
    else return k;
}
int MFKnapsack(int i, int j) {
    int value;
    if (V[i][j] < 0) {
        if (j < Weights[i])
            value = MFKnapsack(i - 1, j);
        else
            value = max(MFKnapsack(i - 1, j), Values[i] + MFKnapsack(i - 1, j - Weights[i]));
        V[i][j] = value;
    }
    return V[i][j];
}
int main() {
    int i, j, val;
    //clrscr();
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
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                V[i][j] = 0;
            } else {
                V[i][j] = -1;
            }
        }
    val = MFKnapsack(n, W);
    printf("The optimal value is %d\n", val);
    printf("The items added are:\n");
    for (i = n, j = W; i > 0; i--) {
        if (V[i][j] != V[i - 1][j]) {
            printf("%d\t", i);
            j = j - Weights[i];
        }
    }
	return 0;
}