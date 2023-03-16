#ifndef _HEAD2_H
#define _HEAD2_H

#include "head1.h"

void funcB(int a, int b) {
    // if (n == 0) return ;
    printf("funcB : %d + %d = %d\n", a, b, a + b);
    funcA(a);
    return ;
}
#endif