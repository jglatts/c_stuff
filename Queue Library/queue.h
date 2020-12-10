#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 5000
#define RED    "\033[1;31m"
#define GREEN  "\033[0;32m"
#define RESET  "\033[0m"
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
