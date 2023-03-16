#include <stdio.h>
// 108.求面积的问题
// 给定一个三角形或长方形的底和高（长和宽），求它的面积

int main() {
    char x;
    double m, n, area;
    scanf("%s%lf%lf", &x, &m, &n);
    switch (x) {
        case 'r': area = m * n; break;
        case 't': area = 0.5 * m * n; break;
    }
    printf("%.2lf\n", area);
    return 0;
}