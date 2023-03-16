#include <stdio.h>
// 144.字符串中A的数量
// 输入一个字符串，统计其中字符 A 的数量并输出

#define MAX_N 100

int count(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'A') count++;
    }
    return count;
}

int main() {
    char str[MAX_N + 5] = {0};
    scanf("%s", str);
    printf("%d\n", count(str));
    return 0;
}