#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Stack* make_new_stack() {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	for (int i = 0; i < MAX_STACK_SIZE; ++i) s->stack[i] = 0;
	s->size = 0;
	return (s != NULL) ? s : NULL;
}

void push(Stack* s, int d) {
	int copy = s->size;
	s->stack[s->size++] = d;    
	printf("Pushed %d on the stack, stack size = %d\n", s->stack[copy], copy+1);
}

int pop(Stack* s) {
	if (s->size == -1) return -1; 
	if (s->size == 0) {
		s->size = -1;
		return s->stack[0];
	}
	s->size--;
	return s->stack[s->size]; 
}

int is_empty(Stack* s) {
	return s->size == 0;
}

void test_stack() {
        Stack* stack = make_new_stack();
        int n, k;
        srand((unsigned)time(NULL));
        printf("------------JDG STACK------------\n");
        printf("How Many Elements In The Stack? -> ");
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
                push(stack, rand() % n);
	}
	printf("\n%s", "Items on stack: ");
        while (!is_empty(stack)) {
		printf("%d ", pop(stack));
	}
	puts("");
}

