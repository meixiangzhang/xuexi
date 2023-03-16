#include <stdio.h>
// 128. n 个数的平均数
// 读入 n 个整数，计算它们的平均值

#define MAX_N 1000

int X[MAX_N + 5];

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", X + i);
        sum += X[i];
    }
    printf("%.2lf\n", (double) sum / (double) n);
    return 0;
}