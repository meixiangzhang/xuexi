#include <stdio.h>
// 120.日期合法性
// 输入一个日期，判断这个日期是否存在

int panduan(int y, int m, int d) {
    if (m <= 0 || m > 12 || d <= 0 || d > 31) return 0;
    int arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (!(y % 4) && (y % 100) || !(y % 400)) arr[2] += 1;
    if (d <= arr[m]) return 1;
    return 0;
}

int main() {
    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    printf("%s\n", panduan(y, m, d) ? "YES" : "NO");
    return 0;
}