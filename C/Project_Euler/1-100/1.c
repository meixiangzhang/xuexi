#include <stdio.h>

int main() {
    int sum1, sum2, sum3;
    sum1 = (3 + 999) * (999 / 3) / 2;
    sum2 = (5 + 995) * (995 / 5) / 2;
    sum3 = (15 + 990) * (990 / 15) / 2;
    printf("sum1 = %d, sum2 = %d, sum3 = %d\n", sum1, sum2, sum3);
    printf("%d\n", sum1 + sum2 - sum3); // 233168
    return 0;
}