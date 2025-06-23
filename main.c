#include <stdio.h>
#include <string.h>

#include "interpret.h"
#include "stack.h"
#include "list.h"

// Declaração das variáveis globais, que já estão definidas em interpret.c
extern Stack *s;
extern List *l;

static void repl()
{
    char line[1024];
    for (;;)
    {
        printf("> ");

        if (!fgets(line, sizeof(line), stdin))
        {
            printf("\n");
            break;
        }

        if (strncmp(line, "exit", 4) == 0)
            break;

        interpret(line);
    }
}

int main () {
    s_init();
    repl();
    return 0;
}
