#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "interpret.h"
#include "stack.h"
#include "list.h"

Stack *s = NULL;
List *l = NULL;

void s_init(){
    s = new_stack(100);
}

void interpret (const char *source) {
    char op[10];
    char arg[10];

    sscanf (source, "%s%s", op, arg);
    //printf("operação: %s\n", op);
    //printf("argumento: %s\n",  arg);

    if(strcmp(op, "push") == 0){
        int value;
        if(sscanf (arg,"%d",&value) == 0){
            value = list_get(l,arg);
        }
        stack_push(s, value);
    } else if (strcmp(op, "add") == 0){
        int arg1 = stack_pop(s);
        int arg2 = stack_pop(s);
        stack_push(s, arg1+arg2);
    } else if (strcmp(op, "sub") == 0){
        int arg1 = stack_pop(s);
        int arg2 = stack_pop(s);
        stack_push(s, arg1-arg2);
    } else if (strcmp(op, "div") == 0){
        int arg1 = stack_pop(s);
        int arg2 = stack_pop(s);
        stack_push(s, arg1/arg2);
    } else if (strcmp(op, "mul") == 0){
        int arg1 = stack_pop(s);
        int arg2 = stack_pop(s);
        stack_push(s, arg1*arg2);
    } else if (strcmp(op, "print") == 0){
        printf("%d\n", stack_pop(s));
    } else if (strcmp(op, "pop") == 0){
        int arg1 = stack_pop(s);
        if (list_exist(l,arg)){
            list_set(l,arg,arg1);
        }else {
            list_append(l,arg,arg1);
        }
    }

    //stack_print(s);
}
