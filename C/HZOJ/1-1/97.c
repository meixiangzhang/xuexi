#include <stdio.h>
#include <inttypes.h> // #include <stdint.h>
// 97.求和2
// 输入一个正整数 n (1 <= n <= 1000000)，你需要计算 1+2+......+n 的值
// 考虑溢出，四字节的int最多可表示10位十进制数

int main() {
    int64_t n;
    scanf("%ld", &n);
    printf("%ld\n", n * (n + 1) / 2);
    // printf("%ld", sizeof(n));
    return 0;
}