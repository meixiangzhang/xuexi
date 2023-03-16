#include <stdio.h>
#define MAX_N 100
// 求N以内的数的最小素因子

int prime[MAX_N + 5];

void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= MAX_N; j += i) {
            if (prime[j]) continue;
            prime[j] = i;
        }
    }
}

int main() {
    init();
    for (int i = 2; i <= MAX_N; i++) {
        printf("min_fac(%d) = %d\n", i, prime[i]);
    }
    
    
    return 0;
}