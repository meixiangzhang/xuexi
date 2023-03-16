#include <stdio.h>
// 146.字符串
// 输入一个字符串，将其中所有的大写和小写字母改成该字母的下一个字母，z 的下一个字母为 a 。

#define MAX_N 50

int main() {
    char str[MAX_N + 5] = {0};
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] < 'Z') {
            str[i] += 1;
        } else if (str[i] >= 'a' && str[i] < 'z') {
            str[i] += 1;
        } else if (str[i] == 'Z') {
            str[i] = 'A';
        } else if (str[i] == 'z') {
            str[i] = 'a';
        } 
    }
    printf("%s\n", str);
    return 0;
}