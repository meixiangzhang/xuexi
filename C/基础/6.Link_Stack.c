#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node head;
    int size;
} Stack;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

Stack *init() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->head.next = NULL;
    s->size = 0;
    return s;
}

int empty(Stack *s) {
    return s->size == 0;
}

int top(Stack *s) {
    return s->head.data;
}

int push(Stack *s, int val) {
    if (s == NULL) return 0;
    Node *node = getNewNode(val);
    s->head.next = node;
    s->head.data = node->data;
    s->size += 1;
    return 1;
}

int pop(Stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    Node *temp = s->head.next;
    s->head.next = temp->next;
    clear_node(temp);
    s->size -= 1;
    return 1;
}

void clear_node(Node *node) {
    if (node == NULL) return ;
    free(node);
    return ;
}

void clear(Stack *s) {
    if (s == NULL) return ;
    Node *p = s->head.next, *temp;
    while (p != NULL) {
        temp = p->next;
        clear_node(p);
        p = temp;
    } 
    free(s);
    return ;
}

int main() {
    return 0;
}