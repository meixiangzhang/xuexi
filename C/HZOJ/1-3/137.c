#include <stdio.h>
// 137.字母三角形

int main() {
    int n, sum = 65;
    scanf("%d", &n);
    if (n >= 7) return 0;
    int k = n;
    for (int i = 0; i < n; i++) {
        for (int j = k; j > 0; j--) {
            printf("%c", sum++);
        }
        k--;
        printf("\n");
    }
    return 0;
}