#include <stdio.h>
// 448.抽奖

#define MAX_N 100

int choujiang(int *arr, int n, int num) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) return i + 1;
    }
    return 0;
}

int main() {
    int n, num, arr[MAX_N + 5] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    scanf("%d", &num);
    printf("%d", choujiang(arr, n, num));
    return 0;
}