#include <stdio.h>
// 103.整除问题
// 判断一个整数 a 能否被另一个整数 b 整除

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%s\n", a % b ? "NO" : "YES"); 
    return 0;
}