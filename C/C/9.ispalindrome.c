#include <stdio.h>

// bool ispalindrome(int x) {
//     // 回文整数
//     if (__builtin_expect(!!(x < 0), 0)) return false;
//     int y = 0, z = x;
//     while (x) {
//         y = y * 10 + x % 10;
//         x /= 10;
//     }
//     return z == y;
// }

// int check(int n, int base) {
//     if (n < 0) return 0;
//     int temp = 0, x = n;
//     while (n) {
//         temp = temp * base + n % base;
//         n /= base;
//     }
//     return temp == x;
// }

int check(int n) {
    if (n < 0) return 0;
    int temp = 0, x = n;
    while (n) {
        temp = temp * 10 + n % 10;
        n /= 10;
    }
    return temp == x;
}

int main() {
    // 检查一个数是否是回文整数，有多少位
    int n, digit = 0, x;
    scanf("%d", &n);
    x = n;
    printf("%d %s\n", x, check(x) ? "is reverse num" : "is not reverse num");
    do {
        n /= 10;
        digit += 1;
    } while (n);
    printf("%d has %d digits\n", x, digit);
    return 0;
}