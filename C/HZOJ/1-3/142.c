#include <stdio.h>
// 142.回文质数

int is_prime(int n) {
    for (int i = 2; i * i <= n; i++) { // 如果 n 为合数，n = a * b -> a <= n^(1/2), b >= n^(1/2)
        if (n % i == 0) return 0;
    }
    return 1;
}

int reverse_num(int n) {
    int y = 0, z = n;
    while (n) {
        y = y * 10 + n % 10;
        n /= 10;
    }
    return z == y;
}

int main() {
    int a, b, min, max, count = 0;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (is_prime(i) && reverse_num(i)) {
            count && printf(" ");
            count++;
            printf("%d", i);
        }
    }
    printf("\n");
    return 0;
}