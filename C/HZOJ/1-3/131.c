#include <stdio.h>
#include <stdint.h>
// 131. n 个数的极差
// 极差是指一组数据中，最大值与最小值之差
// 现在输出一组数字，计算这组数字的极差

#define MAX_N 100

int X[MAX_N + 5];

int main() {
    int n, min = INT32_MAX, max = INT32_MIN;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", X + i);
        if (X[i] > max) max = X[i];
        if (X[i] < min) min = X[i];
    }
    printf("%d\n", max - min);
    return 0;
}