#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

typedef struct Queue {
    int *data;
    int head, tail, length;
    int count;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->length = n;
    q->head = q->tail = 0;
    q->count = 0;
    return q;
}

int empty(Queue *q) {
    // return q->head == q->tail;
    return q->count == 0;
}

int front(Queue *q) {
    return q->data[q->head];
}

int expand(Queue *q) {
    int extr_size = q->length;
    int *p;
    while (extr_size) {
        p = (int *)malloc(sizeof(int) * (q->length + extr_size));
        if (p != NULL) break;
        extr_size >>= 1;
    }
    if (p == NULL) return 0;
    for (int i = q->head, j = 0; j < q->count; j++) {
        p[j] = q->data[(i + j) % q->length];
    }
    free(q->data);
    q->data = p;
    q->head = 0, q->tail = q->count;
    q->length += extr_size;
    return 1;
}

int push(Queue *q, int val) {
    if (q == NULL) return 0;
    // if (q->tail == q->length) return 0;
    // if (q->count == q->length) return 0;
    if (q->count == q->length) {
        if (!expand(q)) return 0;
        printf(GREEN("success to expand! the size = %d\n"), q->length);
    }
    /* // q->data[q->tail] = val; // 这两句可以写成一句，修改如下
    // q->tail += 1; */
    q->data[q->tail++] = val;
    if (q->tail == q->length) q->tail = 0;
    q->count += 1;
    return 1;
}

int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head += 1;
    if (q->head == q->length) q->head = 0;
    q->count -= 1;
    return 1;
}

void clear(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

void output(Queue *q) {
    printf("Queue : [");
    // for (int i = q->head; i < q->tail; i++) {
    //     i != q->head && printf(" ");
    //     printf("%d", q->data[i]);
    // }
    for (int i = q->head, j = 0; j < q->count; j++) {
        j && printf(" ");
        printf("%d", q->data[(i + j) % q->length]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    /* // Queue *q = init(MAX_OP); // 初始化10个会发生假溢出 */
    Queue *q = init(1);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4;
        int val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d to Queue = %d\n", val, push(q, val));
            } break;
            case 3: {
                if (empty(q)) {
                    printf("fail to pop a item!\n");
                } else {
                    printf("success to pop a item : %d\n", front(q));
                    pop(q);
                }
            } break;
        }
        output(q), printf("\n");
    }
    #undef MAX_OP
    clear(q);
    return 0;
}