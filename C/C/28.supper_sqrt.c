#include <stdio.h>
#include <math.h>
// 求开平方根，时间复杂度O（1），但是我看不懂

float InvSqrt(float x) {
    float xhalf = 0.5f * x;
    int i = *(int*)&x; // get bits for floating VALUE
    i = 0x5f375a86 - (i >> 1); // gives initial guess y0
    x = *(float*)&i; // convert bits BACK to float
    x = x * (1.5f - xhalf * x * x); //Newton step, repeating increases accuracy
    x = x * (1.5f - xhalf * x * x); //Newton step, repeating increases accuracy
    x = x * (1.5f - xhalf * x * x); //Newton step, repeating increases accuracy
    return 1 / x;
}

int main() {
    double n;
    while (~scanf("%lf", &n)) {
        printf("my_sqrt(%g) = %g\n", n, InvSqrt(n));
        printf("sqrt(%g) = %g\n", n, sqrt(n));
    }
    return 0;
}