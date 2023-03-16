#include <stdio.h>
#define MAX_N 100
// 线性筛算法

int prime[MAX_N + 5];
void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int main() {
    init();
    for (int i = 1; i < prime[0]; i++) {
        printf("%d\n", prime[i]);
    }
    return 0;
}