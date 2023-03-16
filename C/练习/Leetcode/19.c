#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node head; // 虚拟头节点
    int length;
} List;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

List *init_list() {
    List *l = (List *)malloc(sizeof(List));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

void clear_node(Node *node) {
    if (node == NULL) return ;
    free(node);
    return ;
}

int erase_vn(List *l, int n) {
    if (l == NULL) return 0;
    if (n > l->length) return 0;
    int ind = l->length - n;
    Node *p = &(l->head), *q;
    while (ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    clear_node(q);
    l->length -= 1;
    return 1;
}

void output(List *l) {
    if (l == NULL) return ;
    printf("[");
    for (Node *p = l->head.next; p != NULL; p = p->next) {
        printf("%d");
        (p->next) && printf(",");
    }
    printf("]\n");
}

int main() {
    int n;
    List *l;
    scanf("%d", &n);
    return 0;
}