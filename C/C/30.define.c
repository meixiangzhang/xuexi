#include <stdio.h>
#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b; b =__temp; \
}

#define TYPE(a) _Generic((a), \ // 泛型宏
    int : "%d", \
    double : "%lf" \
)

__attribute__((constructor))
void add(int a, int b) {
    a = 2, b = 3;
    printf("add: %d + %d = %d\n", a, b, a + b);
    return ;
}

int main() {
    int a = 123;
    double b = 3.14;
    printf("main: \n");
    printf(TYPE(a), a);
    printf("\n");
    printf(TYPE(b), b);
    printf("\n");
    return 0;
}