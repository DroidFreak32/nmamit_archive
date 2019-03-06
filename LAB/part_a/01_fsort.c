#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct frame {
    int seqno;
    char msg[100];
} m[100];
int main() {
    int n, i, j, r, s[100], temp;
    char ch[100];
    printf("Enter the number of frames:");
    scanf("%d", & n);
    for (i = 0; i < n; i++) {
        s[i] = -1;
        m[i].seqno = -1;
    }
    j = 0;
    while (j < n) {
        r = rand() % n;
        if (s[r] == -1) {
            m[j].seqno = r;
            j = j + 1;
            s[r] = 1;
        }
    }
    for (i = 0; i < n; i++) {
        printf("Enter the message:");
        scanf("%s", m[i].msg);
        // srand(i);
    }
    printf("The arrived frames are:\n");
    for (i = 0; i < n; i++) {

        printf("%d\t%s\n", m[i].seqno, m[i].msg);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (m[j].seqno > m[j + 1].seqno) {
                temp = m[j].seqno;
                m[j].seqno = m[j + 1].seqno;
                m[j + 1].seqno = temp;
                strcpy(ch, m[j].msg);
                strcpy(m[j].msg, m[j + 1].msg);
                strcpy(m[j + 1].msg, ch);
            }
        }
    }
    printf("The frames in sorted are :\n Sequence number Message \n");
    for (i = 0; i < n; i++) {
        printf("%d\t%s\n", m[i].seqno, m[i].msg);
    }
    printf("\n");
}