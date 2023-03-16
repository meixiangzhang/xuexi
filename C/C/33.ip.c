#include <stdio.h>

union IP {
    struct {
        unsigned char a1;
        unsigned char a2;
        unsigned char a3;
        unsigned char a4;
    } ip;
    unsigned int num;    
};

// 判断电脑是大端机还是小端机
// 小端机：数字低位存储在低地址
// 大端机：数字低位存储在高地址
int is_little() {
    int num = 1;
    return ((char *)(&num))[0];
}


int main() {
    printf("%d\n", is_little());
    union IP p;
    char str[100] = {0};
    int arr[4];
    while (~scanf("%s", str)) {
        sscanf(str, "%d.%d.%d.%d", &arr[0], &arr[1], &arr[2], &arr[3]);
        // p.ip.a1 = arr[0];
        // p.ip.a2 = arr[1];
        // p.ip.a3 = arr[2];
        // p.ip.a4 = arr[3];
        // printf("%d\n", p.num);
        p.ip.a1 = arr[3];
        p.ip.a2 = arr[2];
        p.ip.a3 = arr[1];
        p.ip.a4 = arr[0];
        printf("%u\n", p.num);
    }
    return 0;
}

// 下面实现的也是ip转整数的功能，但是我没看懂
// union Ip {
//     int num;
//     char part[4];
// };

// int main() {
//     int num[4];
//     scanf("%d.%d.%d.%d", num + 3, num + 2, num + 1, num + 0);
//     union Ip ip;
//     for (int i = 3; i >= 0; i--) {
//         ip.part[i] = num[i] & ((1 << 8) - 1);
//         printf("%02X\n", num[i]);
//     }
//     printf("%08X\n", ip.num);
//     return 0;
// }
