#include <stdio.h>

int main() {
    // 输入输出测试
    // int n;
    // while (scanf("%d", &n) != EOF) {
    //     printf(" has %d digits!\n", printf("%d", n));
    // }

    int n;
    char str[100];
    scanf("%[^\n]s", str);
    n = printf("%s", str);
    printf(" has %d digits\n", n);
    
    return 0;
}