#include <stdio.h>

// 扩展欧几里得算法：a * x + b * y = gcd(a, b)
int ex_gcd(int a, int b, int *x, int *y) {
    if (!b) {
        *x = 1, *y = 0;
        return a;
    }
    // int xx, yy, ret = ex_gcd(b, a % b, &xx, &yy);
    // *x = yy;
    // *y = xx - a / b * yy;
    int ret = ex_gcd(b, a % b, y, x);
    *y -= a / b * (*x); // 不太懂
    return ret;
}

int main() {
    int a, b, x, y;
    while (~scanf("%d%d", &a, &b)) {
        printf("gcd(%d, %d) = %d\n", a, b, ex_gcd(a, b, &x, &y));
        printf("%d * %d + %d * %d = %d\n", a, x, b, y, a * x + b * y);
    }
    return 0;
}