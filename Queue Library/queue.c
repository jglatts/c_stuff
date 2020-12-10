#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Queue* make_new_queue() {
        Queue* q = (Queue*)malloc(sizeof(Queue));
        for (int i = 0; i < MAX_QUEUE_SIZE; ++i) q->queue[i] = 0;
        q->size = 0;
        q->index = 0;
        return (q != NULL) ? q : NULL;
}

void enqueue(Queue* q, int d) {
        int copy = q->size;
        q->queue[q->size++] = d;
        #ifdef USE_VERBOSE
        printf("Enqueued %d, queue size = %d\n", q->queue[copy], copy+1);
        #endif
}

int dequeue(Queue* q) {
        if (q->size == -1) return -1;
        if (q->size == 0) {
                q->size = -1;
                return q->queue[0];
        }
        q->size--;
        return q->queue[q->index++];
}

int is_empty(Queue* q) {
        return q->size == 0;
}

void test_queue() {
        Queue* q = make_new_queue();
        int n = 0, c = 0;
        srand((unsigned)time(NULL));
        printf("------------JDG STACK------------\n");
        printf("How Many Elements In The Queue? -> ");
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) enqueue(q, rand() % n);
        puts("\nItems on queue: ");
        while (!is_empty(q)) {
                printf(GREEN);
                printf("%5d", dequeue(q));
                printf(RESET);
                //if (c == 0) continue;
                c++;
                if (c % 10 == 0) puts("");
        }
        puts("");
}
