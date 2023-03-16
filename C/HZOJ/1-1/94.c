#include <stdio.h>
// 94.计算BMI
// 读入两个实数表示体重 w 和身高 h ，输出 BMI 的值

int main() {
    double w, h;
    scanf("%lf%lf", &w, &h);
    printf("%.2lf\n", w / (h * h)); // BMI = w / (h * h)
    return 0;
}