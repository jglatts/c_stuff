#ifndef STACK_H
#define STACK_H

#define MAX_STACK_SIZE 100

typedef struct {
	int stack[MAX_STACK_SIZE];
	int size;
} Stack;

Stack* make_new_stack();
void push(Stack*, int);
void test_stack();
int pop(Stack*);
int is_empty(Stack*);

#endif // STACK_H
