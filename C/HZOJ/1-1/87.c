#include <stdio.h>
// 87.矩形的面积与周长
// 对于一个给定长和宽的矩形，输出它的周长和面积

int main() {
    double a, b;
    scanf("%lf%lf", &a, &b);
    printf("%.2lf\n", 2 * (a + b)); // 周长
    printf("%.2lf\n", a * b); // 面积
    return 0;
}