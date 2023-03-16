#include <stdio.h>
#define MAX_N 100
#include <inttypes.h>

// Triangle: Tn = n(n+1)/2
// Pentagonal: Pn = n(3n-1)/2
// Hexagonal: Hn = n(2n-1)
// T285 = P165 = H143 = 40755

int64_t Triangle(int64_t n) {
    return n * (n + 1) >> 1;
}

int64_t Pentagonal(int64_t n) {
    return n * (3 * n - 1) >> 1;
}

int64_t Hexagonal(int64_t n) {
    return n * (2 * n - 1);
}

// 函数指针
// int g(int (*f1)(int), int (*f2)(int), int (*f3)(int), int x) {
//     if (x < 0) {
//         return f1(x);
//     }
//     if (x <100) {
//         return f2(x);
//     }
//     return f3(x);
// }

// int binary_search(int *arr, int l, int r, int x) {
//     if (l > r) return -1;
//     int mid = (l + r) >> 1;
//     if (arr[mid] == x) return mid;
//     if (arr[mid] < x) l = mid + 1;
//     else r = mid - 1;
//     return binary_search(arr, l, r, x);
// }

// int binary_search(int *arr, int n, int x) {
//     int head = 0, tail = n - 1, mid;
//     while (head <= tail) {
//         mid = (head + tail) >> 1;
//         if (arr[mid] == x) return mid;
//         if (arr[mid] < x) head = mid + 1;
//         else tail = mid -1;
//     }
//     return 0;
// }

// int main() {
//     int arr[MAX_N + 5] = {0};
//     int n, x;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }
//     while (~scanf("%d", &x)) {
//         printf("%d\n", binary_search(arr, n, x));
//     }
//     // while (~scanf("%d", &x)) {
//     //     printf("%d\n", binary_search(arr, 0, n - 1, x));
//     // }
//     return 0;
// }

int64_t binary_search(int64_t (*arr)(int64_t), int64_t n, int64_t x) {
    int64_t head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (arr(mid) == x) return mid;
        if (arr(mid) < x) head = mid + 1;
        else tail = mid -1;
    }
    return 0;
}

int main() {
    int64_t n = 143;
    while (1) {
        n++;
        int64_t temp = Hexagonal(n);
        if (!binary_search(Pentagonal, temp, temp)) continue;
        printf("%ld\n", temp);
        break;
    }
    return 0;
}