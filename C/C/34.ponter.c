#include <stdio.h>
// 指针的表现形式

#define P(func) {\
    printf("%s = %d\n", #func, func);\
}

struct Data {
    int x, y;
};

int main() {
    struct Data a[2], *p = a; // a[1].x
    a[0].x = 0, a[0].y = 1;
    a[1].x = 2, a[1].y = 3;
    P(a[1].x);
    P((a + 1)->x);
    P((p + 1)->x);
    P(p[1].x);
    P((&a[1])->x);
    P((&p[1])->x);
    P((*(a + 1)).x);
    P((*(p + 1)).x);
    P((*(&a[1])).x);
    P((*(&p[1])).x);
    return 0;
}