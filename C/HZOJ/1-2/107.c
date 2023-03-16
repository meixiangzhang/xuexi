#include <stdio.h>
// 107.七的奇倍数
// 如果一个数既是 7 的倍数又不能被 2 整除，那么我们称之为七的奇倍数。
//​ 输入一个正整数 n ，判断它是否是 7 的奇倍数。

int main() {
    int n;
    scanf("%d", &n);
    printf("%s\n", (!(n % 7) & (n % 2)) ? "YES" : "NO");
    return 0;
}