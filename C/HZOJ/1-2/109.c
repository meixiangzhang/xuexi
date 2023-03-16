#include <stdio.h>
// 109.四位数中有偶数位么
// 输入一个四位的正整数，判断它的各个位上是否存在偶数

const char* panduan(int n) { // 当返回值是字符串时，这样定义
    if (!(n / 1000 % 2)) return "YES"; // 千位
    if (!(n / 100 % 10 % 2)) return "YES"; // 百位
    if (!(n % 100 / 10 % 2)) return "YES"; // 十位
    if (!(n % 10 % 2)) return "YES"; // 个位
    return "NO";
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%s\n", panduan(n));
    return 0;
}