#include <stdio.h>
// 139.输出 A 字菱形

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < n - i) { // 为什么去掉中括号把下面两句写到一起没办法正确打印？
                printf(" "); 
                continue;
            }
            printf("AA");
        }
        printf("\n");
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < n; j++) {
            if (j < n - i) {
                printf(" "); 
                continue;
            }
            printf("AA");
        }
        printf("\n");
    }

    return 0;
}