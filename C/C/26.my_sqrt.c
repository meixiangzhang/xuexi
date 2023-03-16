#include <stdio.h>
#include <math.h>
// gcc 26.my_sqrt.c -lm 编译时末尾加上-lm

double my_sqrt(double x) {
    double head = 0, tail = x, mid;
    if (x < 1.0) tail = 1.0;
    #define EPSL 1e-7
    while (tail - head > EPSL) {
        mid = (head + tail) / 2.0;
        if (mid * mid < x) head = mid;
        else tail = mid;
    }
    #undef EPSL
    return head;
}

int main() {
    double x;
    while (~scanf("%lf", &x)) {
        printf("sqrt(%g) = %g\n", x, sqrt(x));
        printf("my_sqrt(%g) = %g\n", x, my_sqrt(x));
    }
    return 0;
}