#include <stdio.h>
// 101.计算各位和
// 输入一个不超过10000的整数 n ，计算它每一位上的数字总和

int geweihe(int n) {
    static int sum = 0;
    if (n / 10) sum = sum + n % 10 + geweihe(n / 10);
    else sum += n;
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", geweihe(n));
    return 0;
}