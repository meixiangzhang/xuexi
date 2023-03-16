#include <stdio.h>

#define MAX_N 100000

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

// 单边递归，时间复杂度稳定在O(NlogN)
void quick_sort(int *num, int l, int r) {
    while (l > r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do {
            while (num[x] < z) x++;
            while (num[y] > z) y--;
            if (x <= y) {
            swap(num[x], num[y]);
            x++, y--;
            }
        } while (x <= y);
    quick_sort(num, l, y);
    l = x;
    }
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