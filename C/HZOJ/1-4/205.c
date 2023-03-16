#include <stdio.h>
// 205.队列行平均数

double hang_avg(int n, int m, int arr[][m]) {
    double sum = 0.0;
    for (int i = 0; i < m; i++) {
        sum += arr[n][i];
    }
    return sum / m;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%.6lf\n", hang_avg(i, m, arr));
    }
    return 0;
}