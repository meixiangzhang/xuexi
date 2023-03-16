#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 扩容报错：最后发现32行少了一个=

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

typedef struct Vector {
    int *data;
    int size,length;
} Vector;

Vector *init(int n) {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (int *)malloc(sizeof(int) * n);
    v->size = n;
    v->length = 0;
    return v;
}

int expand(Vector *v) {
    /* // v->data = realloc(v->data, sizeof(int) * (v->size * 2)); // 扩容不一定能够成功，修改如下
    // v->size <<= 1; */
    int extra_size = v->size;
    int *p;
    while (extra_size) {
        p = (int *)realloc(v->data, sizeof(int) * (v->size + extra_size));
        if (p != NULL) break;
        extra_size >>= 1;
    }
    if (p == NULL) return 0;
    v->data = p;
    v->size += extra_size;
    return 1;
}

int insert(Vector *v, int ind, int val) {
    if (v == NULL) return 0;
    /* // if (v->length == v->size) return 0; // 顺序表满了，看是否可以进行扩容，修改如下 */
    if (v->length == v->size) {
        if (!expand(v)) return 0;
        printf(GREEN("success to expand! the size = %d\n"), v->size);
    }
    if (ind < 0 || ind > v->length) return 0; // 我觉得应该是ind >= v->length, 忘记了还可以在最后一个位置插入
    for (int i = v->length; i > ind; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[ind] = val;
    v->length += 1;
    return 1;
}

int erase(Vector *v, int ind) {
    if (v == NULL) return 0;
    if (ind < 0 || ind >= v->length) return 0;
    /* // for (int i = ind; i < v->length; i++) { // 可能发生内存越界，更改如下
    //     v->data[i] = v->data[i + 1];
    // } */
    for (int i = ind + 1; i < v->length; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->length -= 1;
    return 1;
}

void output(Vector *v) {
    if (v == NULL) return ;
    printf("Vector : [");
    for (int i = 0; i < v->length; i++) {
        i && printf(" ");
        printf("%d", v->data[i]);
    }
    printf("]\n");
    return ;
}

void clear(Vector *v) {
    if (v == NULL) return ;
    free(v->data);
    free(v);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Vector *v = init(1);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 2;
        int val = rand() % 100;
        // int ind = rand() % (v->length + 1);
        int ind = rand() % (v->length + 3) - 1;
        switch (op) {
            case 0: {
                printf("insert %d at %d to Vector = %d\n", val, ind, insert(v, ind, val));
            } break;
            case 1: {
                printf("erase a item at %d from Vector = %d\n", ind, erase(v, ind));
            } break;
        }
        output(v), printf("\n");
    }
    #undef MAX_OP
    clear(v);
    return 0;
}