#include <stdio.h>
typedef unsigned int uint;
uint gcd(uint x, uint y) {
    return y == 0 ? x : gcd(y, x % y);
}
uint multi(uint txt, uint ed, uint n) {
    uint i, rem = 1;
    for (i = 1; i <= ed; i++)
        rem = (rem * txt) % n;
    return rem;
}
short prime(uint no) {
    uint i;
    for (i = 2; i <= no / 2; i++)
        if (no % i == 0) return 1;
    return 0;
}
int main() {
    char msg[100];
    uint pt[100], ct[100], n, d, e, p, q, z, i, len;
    do {
        printf("\nEnter 2 large prime numbers p & q:\n");
        scanf("%d %d", & p, &q);
    } while (prime(p) || prime(q));
    n = p * q;
    z = (p - 1) * (q - 1);
    do {
        printf("\nEnter prime value of e relative to %d(z): ", z);
        scanf("%d", &e);
    } while (gcd(e, z) != 1 || e > n);
    for (d = 2; d < z; d++)
        if ((e * d) % z == 1)
            break;
    printf("Enter the Message:\n");
    //get message from keybrd. 
    len = read(1, msg, 100) - 1;
    for (i = 0; i < len; i++)
    //store it in plain text array 
        pt[i] = msg[i];
    printf("\nCipher Text: ");
    for (i = 0; i < len; i++)
    //convert plain to cipher text 
        printf("%d ", ct[i] = multi(pt[i], e, n));
    printf("\nPlain Text: ");
    for (i = 0; i < len; i++)
    //convert cipher to plain text 
        printf("%c", multi(ct[i], d, n));
    printf("\n");
}