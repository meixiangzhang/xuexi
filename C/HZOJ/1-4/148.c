#include <stdio.h>
#include <string.h>

#define MAX_N 50

char reverse_string(char *s) {
    int x = (int)(*s), y = 0;
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    char str[MAX_N + 5] = to_string(y);
    return str;
}

int main() {
    char s[MAX_N + 5] = {0};
    scanf("%s", s);
    printf("%s\n", reverse_string(s));
    return 0;
}