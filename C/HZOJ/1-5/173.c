#include <stdio.h>
// 173.统计字符个数
// 输入一行字符，分别统计出其中英文字母，数字，空格，其他字符的个数

#define MAX_N 100

int main() {
    char str[MAX_N];
    int a = 0, b = 0, c = 0, d = 0;
    scanf("%[^\n]", str);
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            a++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            b++;
        } else if (str[i] == ' ') {
            c++;
        } else {
            d++;
        }
    }
    printf("%d %d %d %d\n", a, b, c, d);
    return 0;
}