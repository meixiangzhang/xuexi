#include <stdio.h>
// 95.交换两位数
// 读入一个两位的个位不为零的正整数，将它的十位数和个位数调换后输出

int main () {
    int n;
    scanf("%d", &n);
    printf("%d\n", n % 10 * 10 + n / 10);
    return 0;
}