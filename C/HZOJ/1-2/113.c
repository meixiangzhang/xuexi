#include <stdio.h>
// 113.一个月有多少天
// 给出一个年份 y 和月份 m ，求 y 年 m 月有多少天
// 1020 2 有问题

int hanshu(int y, int m) {
    int d[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((!(y % 4) && (y % 100)) || (!(y % 400))) d[2] += 1;
    return d[m];
}

int main() {
    int y, m;
    scanf("%d%d", &y, &m);
    printf("%d\n", hanshu(y, m));
    return 0;
}