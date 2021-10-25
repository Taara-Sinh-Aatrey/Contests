#include <stdio.h>

int main() {
    register int c;
    int n = 0;  
    c = getchar();
    for (; (c > 47 && c < 58); c=getchar())
        n = n * 10 + c - 48;
    printf("%d", ((n / 3) << 1) + !!(n % 3));
    return 0;
}