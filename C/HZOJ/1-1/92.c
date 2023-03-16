#include <stdio.h>
// 92.圆形面积和周长
// 输入圆形的半径r输出圆形的面积和周长

#define PI 3.14

int main() {
    double r;
    scanf("%lf", &r);
    printf("%.2lf\n", 2 * PI * r); // 圆的周长
    printf("%.2lf\n", PI * r * r); // 圆的面积
    return 0;
}