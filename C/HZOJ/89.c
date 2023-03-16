#include <stdio.h>
// 89.取数位I
// 给定一个两位数的整数，分别输出它的十位数和个位数

int main() {
    int a;
    scanf("%d", &a);
    printf("十位数：%d\n", a / 10);
    printf("个位数：%d\n", a % 10);
    return 0;
}