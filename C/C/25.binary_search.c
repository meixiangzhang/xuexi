#include <stdio.h>
// 二分查找

int binary_search(int *arr, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}
//0000000011111111 找第一个1
int binary_search1(int *arr, int n) {
    int head = 0, tail = n, mid; // 数组中不存在1时也成立
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] == 0) head = mid + 1;
        else tail = mid;
    }
    return head == n ? -1 : head;
}
// 1111111100000000 找最后一个1
int binary_search2(int *arr, int n) {
    int head = -1, tail = n - 1, mid; // 数组中不存在1时也成立
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        // printf("head: %d, mid: %d, tail: %d\n", head, mid, tail);
        if (arr[mid] == 0) tail = mid - 1;
        else head = mid;
    }
    return head;
}

int main() {
    int arr2[10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    printf("%d\n", binary_search2(arr2, 10));
    return 0;

    int arr1[10] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    printf("%d\n", binary_search1(arr1, 10));
    return 0;

    int arr[100] = {0}, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    int x;
    while (~scanf("%d", &x)) {
        printf("%d\n", binary_search(arr, n, x));
    }
    return 0;
}