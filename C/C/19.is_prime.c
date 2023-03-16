#include <stdio.h>
#define MAX_N 100
// 有问题

// int is_prime(int n) {
//     // for (int i = 2; i < n; i++) {
//     for (int i = 2; i * i <= n; i++) { // 如果 n 为合数，n = a * b -> a <= n^(1/2), b >= n^(1/2)
//         if (n % i == 0) return 0;
//     }
//     return 1;
// }

// int main() {
//     int n;
//     while (~scanf("%d", &n)) {
//         printf("%s\n", is_prime(n) ? "Yes" : "No");
//     }
//     return 0;
// }

// int prime[MAX_N + 5] = {0}; // 全局区会自动初始化为0
int prime[MAX_N + 5];

void init() {
    // int cnt = 0;
    for (int i = 2; i <= MAX_N; i++) {
        /* if (prime[i] == 0) {
            for (int j = 2 * i; j <= MAX_N; j += i) {
                prime[j] = 1;
            }
        } */
        if (prime[i]) continue;
        /* cnt += 1;
        prime[cnt] = i; */
        prime[++prime[0]] = i;
        for (int j = i; j <= MAX_N; j += i) { // 重复标记
        // for (int j = i * i; j <= MAX_N; j += i) { // 乘法溢出
        // for (int j = i; j <= MAX_N / i; j ++) {
            prime[j * i] = 1;
        }
    }
    return ;
}

int main() {
    init();
    // for (int i = 2; i <= MAX_N; i++) {
    //     /* if (prime[i] == 0) {
    //         printf("%d\n", i);
    //     } */
    //     if (prime[i]) continue;
    //     printf("%d\n", i);
    // }
    for (int i = 0; i <= prime[0]; i++) {
        printf("%d\n", prime[i]);
    }
    return 0;
}