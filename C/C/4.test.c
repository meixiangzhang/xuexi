#include <stdio.h>
#include <math.h>

#define PI acos(-1)

int main() {
    double x;
    scanf("%lf", &x);
    printf("%lf 的立方根是 %lf", x, pow(x, 1.0 / 3.0)); // 这句报错，我还不明白是为什么
    // double x;
    // scanf("%lf", &x);
    // printf("%lf\n", PI / 180.0 * PI);
    return 0;
}