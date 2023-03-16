#include <stdio.h>

int is_prime(int x) {
    for (int i = 2; i <= x / 2; ++i) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}
// K&r风格的函数定义
// int is_prime(x)
// int x;
// {
//     for (int i = 2; i <= x / 2; i++) {
//         if (x % i == 0) {
//             return 0;
//         }
//     }
//     return 1;
// }

int f(int k, int b, int x) {
    return k * x + b;
}

int main() {
    int k, b;
    scanf("%d%d", &k, &b);
    for (int i = 0; i <= 100; ++i) {
        printf("f(%d) = %d\n", i, f(k, b, i));
    }
    return 0;
}