#include<stdio.h> 
#include<stdlib.h> 
    int power(int x, int y) {
        int i, res = 1;
        for (i = 1; i <= y; i++)
            res = x * res;
        return res;
    }
int main() {
    int input[15], m, r = 0, count = 0, i = 0, z = 0, j = 0, n, t[15], k = 0, a, b, c, cnt = 0, reg = 0;

    for (int i = 0; i < 15; ++i) {
        input[i] = 0;
        t[i] = 0;
    }
    printf("\nenter the number of bits: ");
    scanf("%d", & m);
    printf("\nenter the %d bits: ", m);
    for (i = 0; i < m; i++)
        scanf("%d", & input[i]);
    while (power(2, r) < (m + r + 1))
        r++;
    for (i = 1; i <= (m + r); i++) {
        if (i == power(2, k)) {
            t[i] = 0;
            k++;
        } else
            t[i] = input[j++];
    }
    printf("\n the actual message is: ");
    for (i = 1; i <= (m + r); i++)
        printf("%d", t[i]);
    n = 1;
    while (n <= power(2, r)) {
        i = n;
        while (i <= m + r) {
            for (j = 0; j < n; j++) {
                if ((i + j) <= (m + r) && t[i + j] == 1) {
                    count++;
                }
            }
            i = i + 2 * n;
        }
        if (count % 2 != 0)
            t[n] = 1;
        n = n * 2;
        count = 0;
    }
    printf("\ndata transmitted       :");
    for (i = 1; i <= (m + r); i++)
        printf("%d", t[i]);

    printf("\nenter the data transmitted with one bit error:\n");
    for (i = 1; i <= (m + r); i++)
        scanf("%d", & t[i]);

    printf("\n the errored message is:\n");
    for (i = 1; i <= (m + r); i++)
        printf("%d", t[i]);
    n = 1;
    while (n <= power(2, r)) {
        i = n;
        while (i <= m + r) {
            for (j = 0; j < n; j++) {
                if ((i + j) <= (m + r) && t[i + j] == 1)
                    cnt++;
            }
            i = i + 2 * n;
        }
        if (cnt % 2 != 0) {
            reg += n;
        }
        n = n * 2;
        cnt = 0;
    }
    if (reg == 0) {
        printf("\nno error");
    } else {
        printf("\nerror in position %d", reg);
        t[reg] = !(t[reg]);
        printf("\n the corrected message is:\n");
        for (i = 1; i <= (m + r); i++)
            printf("%d", t[i]);
    }
}