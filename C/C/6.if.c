#include <stdio.h>

int main() {
    // if语句
    int n;
    while (~scanf("%d", &n)) {
        if (!n) {
            printf("FOOLISH\n");
        } else if (n < 60) {
            printf("FAIL\n");
        } else if (n < 75) {
            printf("MEDIUM\n");
        } else printf("GOOD\n");
    }
    // scanf("%d", &n);
    // if (!n) {
    //     printf("FOOLISH\n");
    // } else if (n < 60) {
    //     printf("FAIL\n");
    // } else if (n < 75) {
    //     printf("MEDIUM\n");
    // } else if (n <= 100) {
    //     printf("GOOD\n");
    // }
    // return 0;
}