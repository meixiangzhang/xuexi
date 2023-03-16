#include <stdio.h>
// 124.招聘
// 

int main() {
    int x, pm, age, y; // x 学历，pm 毕业院校的排名，age 年龄大小，y 工作年份
    while (~scanf("%d%d%d%d", &x, &pm, &age, &y)) {
        if ((x >= 1 | pm <= 50) & (age <= 25 | y >= 5)) printf("ok\n");
        else printf("pass\n");
    }
    return 0;
}