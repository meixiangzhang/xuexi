#include <stdio.h>
#include <string.h>
// 181.大小写翻转
// 现在有一个字符串，你需要把字符串中出现的小写字母转换成大写字母，大写字母转换成小写字母。

#define MAX_N 100

char convert(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return *str;
}

int main() {
    char str[MAX_N] = {0};
    scanf("%s", str);
    convert(str);
    printf("%s\n", str);
    return 0;
}