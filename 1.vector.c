#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int extr_size = v->size;
    int *p;
    while (extr_size) {
        p = (int *)realloc(v->data,sizeof(int) * (v->size +  extr_size));
        if (p != NULL) break;
        extr_size >> 1;
    }
    if (p == NULL) return 0;
    v->data = p;
    v->size += extr_size;
    // v->data = (int *)realloc(v->data, sizeof(int) * (v->size * 2));
    // v->size <<= 1;
    return 1;
}

int insert(Vector *v, int ind, int val) {
    if (v == NULL) return 0;
    if (v->length == v->size) return 0;
    if (ind < 0 || ind > v->length) return 0;
    for (int i = v->length; i > ind; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[ind] = val;
    v->length += 1;
    return 1;
}

int erase(Vector *v, int ind) {
    if (v == NULL) return 0;
    if (ind < 0 || ind > v->length) return 0;
    for (int i = ind; i < v->length; i++) {
        v->data[i] = v->data[i + 1];
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
    Vector *v = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 2;
        int val = rand() % 100;
        int ind = rand() % (v->length + 1);
        switch (op) {
            case 0: {
                printf("insert %d at %d to Vector = %d\n", val, ind, insert(v, ind, val));
            } break;
            case 1: {
                printf("erase a iterm at %d from Vector = %d\n", ind, erase(v, ind));
            } break;
        }
        output(v), printf("\n");
    }
    #undef MAX_OP
    clear(v);
    return 0;
} 
