#include <stdio.h>
// 90.取位数II
// 给定一个三位数的整数，分别输出它的百位数、十位数和个位数

int main() {
    int a;
    scanf("%d", &a);
    printf("%d\n", a / 100); // 百位数
    printf("%d\n", a / 10 % 10); // 十位数
    printf("%d\n", a% 10); // 个位数
    return 0;
}