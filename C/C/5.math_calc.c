#include <stdio.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

int main() {
    // 交换两个数的值
    int a = 123, b = 456;
    printf("a = %d, b = %d\n", a, b);
    // int temp = a;
    // a = b;
    // b = temp;
    // printf("a = %d, b = %d\n", a, b);
    swap(a, b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
    a ^= b; // 异或：相同为0，不同为1
    b ^= a; // 两个相同的数异或为0
    a ^= b; // 0和A异或为A
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
