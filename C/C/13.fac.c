#include <stdio.h>

// 递归程序
// 函数调用自身的编程技巧叫做 [递归]
// 递归程序的组成部分
// 1、边界条件处理
// 2、针对于问题的 [处理过程] 和 [递归过程]
// 3、结果返回
int fac(int n) {
    if (n == 1) return 1;
    if (n == 0) return 1;
    return n * fac(n - 1);
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        printf("fac(%d) = %d\n", n, fac(n));
    }
    return 0;
}