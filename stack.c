#include "stack.h"
#include <string.h>
#include <stdio.h>

void print_stack(const stack * s) {
    printf("%s", s->stack);
}

void init_stack(stack * s, const char * c) {
    strcpy(s->stack, c);
}

int stack_length(const stack * s) {
    return strlen(s->stack);
}
