#include <stdio.h>
// 141.输出字母沙漏

int main() {
    int n, c = 65;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 2 * n + 1 - i; j++) {
            if (j < i) {
                printf(" ");
                continue;
            } else if (j < n + 1) {
                printf("%c", c + j);
                continue;
            } else
                printf("%c", c - j + 2 * n);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 2 + i; j++) {
            if (j < n - 1 - i) {
                printf(" ");
                continue;
            } else if (j < n + 1) {
                printf("%c", c + j);
                continue;
            } else
                printf("%c", c - j + 2 * n);
        }
        printf("\n");
    }
    return 0;
}