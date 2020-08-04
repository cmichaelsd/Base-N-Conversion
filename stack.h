#ifndef STACK_H
#define STACK_H

typedef struct {
    char stack[64];
} stack;

int stack_length(const stack * s);
void init_stack(stack * s, const char * c);
void print_stack(const stack * s);

#endif
