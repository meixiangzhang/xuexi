#include <stdio.h>
// gcc -E 31.MAX.c 可以查看宏替换之后的代码
// #define MAX(a, b) a > b ? a : b
// #define MAX(a, b) (a > b ? a : b)
// #define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAX(a, b) ({ \
    __typeof(a) _a = (a); \
    __typeof(b) _b = (b); \
    _a > _b ? _a : _b; \
})

#define P(func) { \
    printf("%s = %d\n", #func, func); \
} 

int main() {
    int a = 7;
    P(MAX(2, 3));
    P(5 + MAX(2, 3));
    P(MAX(2, MAX(3, 4)));
    P(MAX(2, 3 > 4 ? 3 : 4));
    P(MAX(a++, 6));
    P(a);
    return 0;
}