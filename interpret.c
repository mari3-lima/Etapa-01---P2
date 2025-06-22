#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "interpret.h"
#include "stack.h"
#include "stack.h"
#include "list.h"

// Definição das variáveis globais
Stack *s = NULL;
List *l = NULL;

void s_init() {
    s = new_stack(100);
    l = new_list();
}

static int is_number(const char* str){
    if (*str == '-' || *str == '+') str++;
    if (!*str) return 0;
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

void interpret(const char *source) {
    char op[10] = {0};
    char arg[15] = {0};

    sscanf(source, "%s %s", op, arg);

    if(strcmp(op, "push") == 0){
        int value;
        if (is_number(arg)) {
            value = atoi(arg);
            stack_push(s, value);
        } else {
            int value = list_get(l, arg);
            if (value == -1) {
                printf("Erro: Variável '%s' não encontrada\n", arg);
            } else {
                stack_push(s, value);
            }
        }

    } else if (strcmp(op, "pop") == 0){
        int val = stack_pop(s);
        if (val == 0 && s->top == 0) {  // pilha vazia já avisada
            return;
        }

        if (list_exist(l, arg)){
            list_set(l, arg, val);
        } else {
            list_append(l, arg, val);
        }

    } else if (strcmp(op, "add") == 0){
        int arg2 = stack_pop(s);
        int arg1 = stack_pop(s);
        stack_push(s, arg1 + arg2);

    } else if (strcmp(op, "sub") == 0){
        int arg2 = stack_pop(s);
        int arg1 = stack_pop(s);
        stack_push(s, arg1 - arg2);

    } else if (strcmp(op, "mul") == 0){
        int arg2 = stack_pop(s);
        int arg1 = stack_pop(s);
        stack_push(s, arg1 * arg2);

    } else if (strcmp(op, "div") == 0){
        int arg2 = stack_pop(s);
        int arg1 = stack_pop(s);
        if (arg2 == 0) {
            printf("Erro: divisão por zero\n");
            stack_push(s, arg1);
            stack_push(s, arg2);
        } else {
            stack_push(s, arg1 / arg2);
        }

    } else if (strcmp(op, "print") == 0){
        if (s->top <= 0) {
            printf("Erro: pilha vazia\n");
            return;
        }
        int val = stack_pop(s);
        printf("%d\n", val);

    } else {
        printf("Erro: comando '%s' desconhecido\n", op);
    }
}
