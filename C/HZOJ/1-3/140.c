#include <stdio.h>
// 140.输出字母菱形

int main() {
    int n, c = 65;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n + i; j++) {
            if (j < n - i) {
                printf(" "); 
                continue;
            }
            printf("%c", c + i);
        }
        printf("\n");
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < n - 1 + i; j++) {
            if (j < n - i) {
                printf(" "); 
                continue;
            }
            printf("%c", c + i - 1);
        }
        printf("\n");
    }

    return 0;
}