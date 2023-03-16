#include <stdio.h>

int main() {
    // while循环
    int x;
    while(~scanf("%d", &x)) {
        printf("x = %d\n", x);
        printf("x-- = %d\n", x--);
        printf("--x = %d\n", --x);
        printf("x++ = %d\n", x++);
        printf("++x = %d\n", ++x);
    }
    int n = 1;
    while (n < 101) {
        printf("%d\n", n);
        n++; // n++ 与 ++n 前置++、--和后置++、--
    }
    return -1;
    do {
        printf("%d\n", n);
        n++;
    } while (n < 101);
    return 0;
}