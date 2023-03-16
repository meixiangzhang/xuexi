#include <stdio.h>
// 100.计算复利
// 假如你每个月向银行账户存100美元，月利率为0.00417。
// 第一个月之后，账户上的值就变成：100 * (1 + 0.00417) = 100.417
// 第二个月之后，账户上的值就变成：(100 + 100.417) * (1 + 0.00417) = 201.252

double fuli(int n, int month) {
    // if (month == 0) return n;
    if (month == 1) return n * (1 + 0.00417);
    else return (n + fuli(n, month - 1)) * (1 + 0.00417);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("$%.2lf\n", fuli(n, 6)); // 六个月后账户上的钱数
    return 0;
}