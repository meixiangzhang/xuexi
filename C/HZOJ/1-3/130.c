#include <stdio.h>
// 130.计算复利2
// 

double fuli2(int m, int n) {
    if (!n) return m;
    if (n == 1) return m * (1 + 0.00417);
    else return (m + fuli2(m, n - 1)) * (1 + 0.00417);
}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    printf("$%.2lf\n", fuli2(m, n));
    return 0;
}