#include <stdio.h> // 系统路径下
#include "head2.h" // 当前路径下
#include "head1.h"

// 函数未声明，在编译期报错
// 函数未定义，在链接期报错

// void funcA(int);
// void funcB(int);

// void funcB(int n) {
//     if (n == 0) return ;
//     printf("funcB : %d\n", n);
//     funcA(n - 1);
//     return ;
// }

// void funcA(int n) {
//     if (n == 0) return ;
//     printf("funcA : %d\n", n);
//     funcB(n - 1);
//     return ;
// }

int main() {
    funcA(5);
    funcB(2, 3);
    return 0;
}