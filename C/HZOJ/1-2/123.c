#include <stdio.h>
// 123.线段包含
// 给定一个数轴上的两条线段，判断两条线段是否存在完全覆盖关系

int main() {
    int a, b, c, d;
    while (~scanf("%d%d%d%d", &a, &b, &c, &d)) {
        if ((a <= c & b >= d) | (a >= c & b <= d)) printf("YES\n");
        else printf("NO");
    }
    return 0;
}