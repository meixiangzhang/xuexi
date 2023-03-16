#include<stdio.h>
// 126.圆环面积
// 有一个大圆半径为 r1 ，在它的中间抠掉一个半径为 r2 的小圆，求剩下的圆环的面积

#define PI 3.14

int main() {
    double r1, r2;
    scanf("%lf%lf", &r1, &r2);
    printf("%.2lf\n", PI * (r1 * r1 - r2 * r2));
    return 0;
}