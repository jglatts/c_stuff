#ifndef STACK_H
#define STACK_H

#define MAX_STACK_SIZE 100
#define RED    "\033[1;31m"
#define GREEN  "\033[0;32m"
#define RESET  "\033[0m"

typedef struct {
        int *stack;
        int size;
} Stack;

Stack* make_new_stack(int);
void push(Stack*, int);
void test_stack();
int pop(Stack*);
int is_empty(Stack*);

#endif // STACK_H
