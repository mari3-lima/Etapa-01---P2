#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Stack* new_stack(int size){
    Stack *s = calloc(1,sizeof(Stack));
    s->values = calloc(size, sizeof(int));
    s->top = 0;
    s->size = size;
    return s;
}

void stack_push(Stack* s, int value){
    if (s->top >= s->size) {
        printf("Erro: pilha cheia\n");
        return;
    }
    s->values[s->top++] = value;
}

int stack_pop(Stack* s){
    if (s->top <= 0) {
        printf("Erro: pilha vazia\n");
        return 0;
    }
    return s->values[--s->top];
}

void stack_print(Stack* s){
    printf("============ STACK ===========\n");
    for(int i = s->top - 1; i >= 0; i--){
        printf("%d\n", s->values[i]);
    }
    printf("============ STACK ===========\n");
}
