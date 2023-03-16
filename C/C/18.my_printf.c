#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

// 有点问题

int reverse_num(int n, int *temp) {
    int digit = 0;
    do {
        *temp = *temp * 10 + n % 10;
        n /= 10;
        digit++;
    } while (n);
    return digit;
}

int output_num(int n, int digit) {
    int cnt = 0;
    while (digit--) {
        putchar(n % 10 + '0'), ++cnt;
        n /= 10;
    }
    return cnt;
}

int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    #define PUTC(a) putchar(a), ++cnt
    for (int i = 0; frm[i]; i++) {
        // putchar(frm[i]), cnt++;
        // PUTC(frm[i]);
        switch (frm[i]) {
            case '%': {
                switch (frm[++i]) {
                    case '%': PUTC(frm[i]); break;
                    case 'd': {
                        // int temp = va_arg(arg, int);
                        // if (temp < 0) PUTC('-'), temp = -temp;
                        // int x = 0, digit = 0;
                        // int x = va_arg(arg, int);
                        // do {
                        //     x = x * 10 + temp % 10;
                        //     temp /= 10;
                        //     digit++;
                        // } while(temp);
                        // while (digit--) {
                        //     PUTC(x % 10 + '0');
                        //     x /= 10;
                        // }
                        int x = va_arg(arg, int);
                        uint32_t xx = 0;
                        if (x < 0) PUTC('-'), xx = -x;
                        else xx = x;
                        int x1 = xx / 100000, x2 = xx % 100000;
                        int temp1 = 0, temp2 = 0;
                        int digit1 = reverse_num(x1, &temp1);
                        int digit2 = reverse_num(x2, &temp2);
                        int digit3 = 0;
                        if (x1) digit3 = 5 - digit2;
                        // if (x1) digit2 = 5;
                        else digit1 = 0;
                        cnt += output_num(temp1, digit1);
                        cnt += output_num(0, digit3);
                        cnt += output_num(temp2, digit2);
                    } break;
                    case 's': {
                        const char *str = va_arg(arg, const char *);
                        for (int i = 0; str[i]; i++) {
                            PUTC(str[i]);
                        } break;
                    }
                }
            } break;
            default: PUTC(frm[i]); break;
        }
    }
    #undef PUTC
    va_end(arg);
    return cnt;
}

int main() {
    int a = 123;
    printf("hello world\n");
    my_printf("hello world\n");
    printf("int (a) = %d\n", a);
    my_printf("int (a) = %d\n", a);
    // my_printf("int(a) = %%\n");
    printf("int (a) = %d\n", 0);
    my_printf("int (a) = %d\n", 0);
    printf("int (a) = %d\n", 1000);
    my_printf("int (a) = %d\n", 1000);
    printf("int (a) = %d\n", -123);
    my_printf("int (a) = %d\n", -123);
    printf("INT32_MAX = %d\n", INT32_MAX);
    my_printf("INT32_MAX = %d\n", INT32_MAX);
    printf("INT32_MIN = %d\n", INT32_MIN);
    my_printf("INT32_MIN = %d\n", INT32_MIN);
    printf("int (-007) = %d\n", -007);
    my_printf("int (-007) = %d\n", -007);
    printf("a = %d\n", 'a');
    my_printf("a = %d\n", 'a');
    printf("int (100500) = %d\n", 100500);
    my_printf("int (100500) = %d\n", 100500);
    char str[] = "I love China!";
    printf("%s\n", str);
    my_printf("%s\n", str);
    int n;
    while (~scanf("%d", &n)) {
        printf(" has %d digits!\n", printf("%d\n", n));
        my_printf(" has %d digits!\n", my_printf("%d\n", n));
    }
    return 0;
}