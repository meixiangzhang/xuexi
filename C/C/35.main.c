#include <stdio.h>

// #define offset(T, a) ({\
//     T temp;\
//     (char *)&temp.a - (char *)&temp;\
// })
#define offset(T, a) ((long)(&((T *)(NULL))->a))

typedef char * pchar;
#define ppchar char *

struct Data {
    int a;
    char b;
    double c;
};

// void output(int argc, char *argv[]) {
void output(int argc, char *argv[], char **env) { // **env 等价于 *env[]
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    for (int i = 0; env[i]; i++) {
        printf("env[%d] = %s\n", i, env[i]);
    }
    return ;
}

// int main() {
int main(int argc, char *argv[], char **env) {
    // output(argc, argv);
    output(argc, argv, env);

    return 0;
    pchar p1, p2;
    ppchar p3, p4;
    printf("p1 = %lu, p2 = %lu\n", sizeof(p1), sizeof(p2));
    printf("p3 = %lu, p4 = %lu\n", sizeof(p3), sizeof(p4));

    return 0;
    printf("%ld\n", offset(struct Data, a));
    printf("%ld\n", offset(struct Data, b));
    printf("%ld\n", offset(struct Data, c));
    return 0;
}