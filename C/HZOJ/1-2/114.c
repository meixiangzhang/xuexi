#include <stdio.h>
// 114.他的名字
// 输入一个字母 x （'a' <= x <= 'z'），输出字母对应的名字

int main() {
    char x;
    scanf("%s", &x);
    switch (x) {
        case 'h': printf("He\n"); break;
        case 'l': printf("Li\n"); break;
        case 'c': printf("Cao\n"); break;
        case 'd': printf("Duan\n"); break;
        case 'w': printf("Wang\n"); break;
        default: printf("Not Here\n"); break;
    }
    return 0;
}