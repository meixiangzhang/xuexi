#include <stdio.h>
// 136.N以内7的倍数
// 给定一个正整数 n，输出 n 以内（含）所有 7 的倍数

int main() {
    int n;
    scanf("%d", &n);
    if (n < 7) return 0;
    for (int i = 7; i <= n; i += 7) {
        printf("%d\n", i);
    }
    return 0;
}