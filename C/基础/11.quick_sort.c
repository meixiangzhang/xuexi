#include <stdio.h>

#define MAX_N 100000

void quick_sort(int *num, int l, int r) {
    if (l > r) return ;
    int x = l, y = r, z = num[x];
    while (x < y) {
        while (x < y && num[y] > z) y--;
        if (x < y) num[x++] = num[y]; // 从右往左，第一个小于基准值的赋给num[x++]
        while (x < y && num[x] < z) x++;
        if (x < y) num[y--] = num[x]; // 从左往右，第一个大于基准值的赋给num[y--]
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return ;
}

void init_arr(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
    return ;
}

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        i && printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    return ;
}

int main() {
    int arr[MAX_N] = {0};
    init_arr(arr, MAX_N);
    quick_sort(arr, 0, MAX_N - 1);
    output(arr, MAX_N);
    return 0;
}