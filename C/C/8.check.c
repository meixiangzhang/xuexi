#include <stdio.h>

int check(int y, int m, int d) {
    if (m <= 0 || m > 12 || d <= 0 || d > 31) return 0;
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (((y & 3) == 0 && y % 100) || y % 400 == 0) month[2] += 1;
    return d <= month[m];
}

int main() {
    // 检查输入的年月日是否是合法的
    int y, m, d;
    // scanf("%d%d%d", &y, &m, &d);
    // printf("%s\n", check(y, m, d) ? "Yes" : "No");
    while (~scanf("%d%d%d", &y, &m, &d)) {
        printf("%s\n", check(y, m, d) ? "Yes" : "No");
    }
    return 0;
}