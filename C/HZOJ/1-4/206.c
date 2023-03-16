#include <stdio.h>

int lie_sum(int n, int m, int j, int arr[n][m]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i][j];
    }
    return sum;
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
    for (int i = 0; i < m; i++) {
        printf("%d\n", lie_sum(n, m, i, arr));
    }
    return 0;
}