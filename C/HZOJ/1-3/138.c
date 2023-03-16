#include <stdio.h>
// 138.输出A字三角形
// 输入一个正整数 n，并输出一个三角形，这个三角形有 n 行，第一行有 2n 个字母 A，之后每行字母 A 的数量会递减 2 个

int main() {
    int n;
    scanf("%d", &n);
    if (n >= 40) return 0;
    int k = 2 * n;
    for (int i = 0; i < n; i++) {
        for (int j = k; j > 0; j--) {
            printf("A");
        }
        k -= 2;
        printf("\n");
    }
    return 0;
}