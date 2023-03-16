#include <stdio.h>

void xuanzhuan(int **arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

        }
    }
    return ;
}

int main() {
    int n, m, arr[n][m];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int j = m - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            i && printf(" ");
            printf("%d", arr[j][i]);
        }
        printf("\n");
    }
    return 0;
}