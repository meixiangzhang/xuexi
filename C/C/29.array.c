#include <stdio.h>
#define MAX_N 100

// 一维数组
// void func(int *p) {
//     printf("sizeof(p) = %ld\n", sizeof(p));
//     printf("func: \n");
//     return ;
// }

// int main() {
//     int arr[MAX_N + 5], n;
//     // scanf("%d", &n);
//     // for (int i = 0; i < n; i++) {
//     //     scanf("%d", &arr[i]);
//     //     // scanf("%d", arr + i); // 和上面那一句是等价的
//     // }
//     int *q = arr;
//     double *temp;
//     printf("arr = %p, &arr[0] = %p\n", arr, &arr[0]);
//     printf("arr + 1 = %p\n", arr + 1);
//     printf("q = %p, q + 1 = %p\n", q, q + 1);
//     printf("temp = %p, temp + 1 = %p\n", temp, temp + 1);
//     func(arr);
//     printf("sizeof(arr) = %lu\n", sizeof(arr));
//     return 0;
// }

// 二维数组
void func(int (*p)[100][2]) { // 二维数组传参：p[MAX_N + 5][100] 或者 (*p)[100]; 三维数组传参：p[MAX_N][100][2] 或者 (*p)[100][2]
    // p + 1 与 p 差了多少个字节
    printf("func: \n");
    return ;
}

int main() {
    int arr[MAX_N + 5][100][2];
    func(arr);
    // arr + 1 与 arr 差了多少个字节
    int **p; // 指针变量也是变量；变量是用来存值的；变量本身有地址
    printf("arr = %p, arr + 1 = %p\n", arr, arr + 1);
    printf("p = %p, p + 1 = %p\n", p, p + 1);
    printf("sizeof(arr) = %lu\n", sizeof(arr));
    return 0;
}