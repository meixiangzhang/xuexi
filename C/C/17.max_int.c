#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>

#define P(func) {\
    printf("%s = %d\n", #func, func);\
}
// 可变参数
// int max_int(int a, ...);
// va_list 类型的变量：获得a往后的参数列表
// va_start 函数：定位a后面第一个参数的位置
// va_arg 函数：获取下一个可变参数列表中的参数
// va_end 函数：结束整个获取可变参数列表的动作
int max_int(int n, ...) {
    int ans = INT32_MIN;
    va_list arg;
    va_start(arg, n);
    while (n--) {
        int temp = va_arg(arg, int);
        if (temp > ans) ans = temp;
    }
    va_end(arg);
    return ans;
}

int main() {
    P(max_int(3, 1, 2, 3));
    P(max_int(5, 1, 3, 5, 13, 1));
    P(max_int(5, 1, 14, 3, 7, 11, 23, 44));
    P(max_int(2, 1.2, 3.14, 3, 4, 1.33));
    // printf("%d\n", max_int(3, 1, 2, 3));
    // printf("%d\n", max_int(5, 1, 3, 5, 13, 1));
    // printf("%d\n", max_int(5, 1, 14, 3, 7, 11, 23, 44));
    return 0;
}