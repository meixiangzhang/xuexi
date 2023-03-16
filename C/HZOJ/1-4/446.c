#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n][n];
    int x = (n + 1) / 2;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) printf("%d", 1); continue;
            if (i >= 1 || j >= 1) printf("%d", 2); continue;
            printf("%d", i);
        }
    }
    return 0;
}