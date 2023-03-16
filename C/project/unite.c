#include <stdio.h>

void funcA(int);
void funcB(int n);

void funcA(int n) {
    if (n == 0) return ;
    printf("funcA : %d\n", n);
    funcB(n - 1);
    return ;
}