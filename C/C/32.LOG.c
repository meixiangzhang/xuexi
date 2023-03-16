#include <stdio.h>

// #func: 转成字符串
// ##args: 连接
// #define DEBUG
// gcc/g++ -DDEBUG 32.LOG.c 编译时定义DEBUG
#ifdef DEBUG
#define log(frm, args...) { \
    printf("[%s : %s : %d] ", __FILE__, __func__, __LINE__); \
    printf(frm, ##args); \
    printf("\n"); \
}
#else
#define log(frm, args...)
#endif

#define contact(a, b) a##b // a##b: 表示连接

int main() {
    int a = 123, b = 234, abc, def;
    int abcdef = 0;
    // printf("[%s : %s : %d] a = %d\n", __FILE__, __func__, __LINE__, a);
    log("a = %d", a);
    log("b = %d", b);
    // printf("hello world\n");
    log("hello world");
    contact(abc, def) = 112233;
    log("%d", abcdef);
    return 0;
}