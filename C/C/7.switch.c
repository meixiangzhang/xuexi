#include <stdio.h>

int main() {
    // switch语句
    int n;
    while (~scanf("%d", &n)) {
        switch (n) {
            case 1: 
                printf("one ");
            case 2:
                printf("two ");
            case 3:
                printf("three\n");
                break;
            default:
                printf("error\n");
            break;
        }
    }
    // scanf("%d", &n);
    // switch (n) {
    //     case 1:
    //         printf("one\n");
    //         break;
    //     case 2:
    //         printf("two\n");
    //         break;
    //     case 3:
    //         printf("three\n");
    //         break;
    //     default:
    //         printf("error\n");
    //         break;
    // }
    return 0;
}