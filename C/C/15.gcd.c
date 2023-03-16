#include <stdio.h>

// 辗转相除
// 定理: a 和 b 两个整数的最大公约数等于 b 与 a % b 的最大公约数
// 形式化表示：假设 a, b != 0 则，gcd(a, b) = gcd(b, a % b)
// 证明1：
//     1、设 c = gcd(a, b), 则 a = cx, b = cy
//     2、可知 a % b = r = a - k * b = cx - kcy = c(x - ky)
//     3、可知 c 也是 r 的因数
//     4、其中 x - ky 与 y 互素，见 证明2
// 所以可知：gcd(a, b) = gcd(b, r) = gcd(b, a % b)
// 证明2：
//     1、假设 gcd(x - ky, y) = d
//     2、则 y = nd, x - ky = md, 则 x = knd  + md = d(kn + m)
//     3、重新表示 a, b, 则有 a = cd(kn + m), b = cdn
//     4、则可得 gcd(a, b) >= cd, 又因为 gcd(a, b) = c, 所以 d=1

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

// lcm(a, b) = a * b / gcd(a, b)
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    int a, b;
    while(~scanf("%d%d", &a, &b)) {
        printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
        printf("lcm(%d, %d) = %d\n", a, b, lcm(a, b));
    }
    return 0;
}