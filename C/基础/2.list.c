#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    // Node *head; // 头指针
    Node head; // 虚拟头节点
    int length;
} List;

Node *getNewNode(int);
List *init_list();
int insert(List *, int, int);
int erase(List *, int);
void clear_node(Node *);
void clear(List *);

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

List *init_list() {
    List *l = (List *)malloc(sizeof(List));
    // l->head = NULL;
    l->head.next = NULL;
    l->length = 0;
    return l;
}

int insert(List *l, int ind, int val) {
    if (l == NULL) return 0;
    if (ind < 0 || ind > l->length) return 0;
    Node *p = &(l->head), *node = getNewNode(val);
    while (ind--) p = p->next;
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}

int erase(List *l, int ind) {
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    Node *p = &(l->head), *q;
    while (ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    clear_node(q);
    l->length -= 1;
    return 1;
}

void clear_node(Node *node) {
    if (node == NULL) return ;
    free(node);
    return ;
}

void clear(List *l) {
    if (l == NULL) return;
    Node *p = l->head.next, *q;
    while (p != NULL) {
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(l);
    return ;
}

void reverse(List *l) { // 好好理解一下这个操作，原地反转
    if (l == NULL) return ;
    Node *p = l->head.next, *q;
    l->head.next = NULL;
    while (p != NULL) {
        q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
}

void output(List *l) {
    if (l == NULL) return ;
    printf("list(%d) : ", l->length);
    for (Node *p = l->head.next; p != NULL; p = p->next) {
        printf("%d->", p->data);
    }
    printf("NULL\n");
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    List *l = init_list();
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4;
        int val = rand() % 100;
        int ind = rand() % (l->length + 3) - 1;
        switch (op) {
            case 0:
            /* case 1:
            case 2: {
                printf("insert %d at %d to List = %d\n", val, ind, insert(l, ind, val));
            } break; */
            case 1: {
                printf("insert %d at %d to List = %d\n", val, ind, insert(l, ind, val));
            } break;
            case 2: {
                printf("reverse the List!\n");
                reverse(l);
            } break;
            case 3: {
                printf("erase a item at %d from List = %d\n", ind, erase(l, ind));
            } break;
        }
        output(l), printf("\n");
    }
    #undef MAX_OP
    clear(l);
    return 0;
}

