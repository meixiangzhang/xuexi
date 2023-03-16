#include <stdio.h>
#include <stdlib.h>
// 118.生肖
// 已知 1900 年是鼠年，输入一个年份，输出其对应生肖

void print_z(int op) {
    switch (op) {
        case 0: printf("rat\n"); break;
        case 1: printf("ox\n"); break;
        case 2: printf("tiger\n"); break;
        case 3: printf("rabbit\n"); break;
        case 4: printf("dragon\n"); break;
        case 5: printf("snake\n"); break;
        case 6: printf("horse\n"); break;
        case 7: printf("sheep\n"); break;
        case 8: printf("monkey\n"); break;
        case 9: printf("rooster\n"); break;
        case 10: printf("dog\n"); break;
        case 11: printf("pig\n"); break;
    }
}

int main() {
    int year;
    scanf("%d", &year);
    year = (year - 1900) % 12;
    if (year >= 0) print_z(year); // (year + 8) % 12 + 1，可以直接写成这样，但是我不明白
    else  print_z(year + 12);
    return 0;
}
