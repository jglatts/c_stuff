#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 100
#define USE_VERBOSE

typedef struct Queue {
        int queue[MAX_QUEUE_SIZE];
        int size;
	int index;
} Queue;

Queue* make_new_queue();
void enqueue(Queue*, int);
void test_queue();
int dequeue(Queue*);
int is_empty(Queue*);

#endif // STACK_H
