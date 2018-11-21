#include <stdio.h>
#include <string.h>
char p[50], t[50];
int table[256];
int m, n;
void shifttable() {
    int i, j, temp;
    for (i = 0; i < 256; i++) {
        table[i] = m;
    }
    for (j = 0; j < m - 1; j++) {
        temp = p[j];
        table[temp] = m - 1 - j;
    }
}
int horspool() {
    int i, k;
    int temp;
    shifttable();
    i = m - 1;
    while (i <= n - 1) {
        k = 0;
        while ((k <= m) && (p[m - 1 - k] == t[i - k]))
            k++;
        if (k == m)
            return (i - m + 1);
        else
            temp = t[i];
        i += table[temp];
    }
    return -1;
}
int main() {
    int r;
    printf("Enter the text\n");
    scanf("%s", t);
    n = strlen(t);
    printf("Enter the pattern\n");
    scanf("%s", p);
    m = strlen(p);
    r = horspool();
    if (r == -1)
        printf("Pattern not found\n");
    else
        printf("Pattern found at position %d\n", r);
}