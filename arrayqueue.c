#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef CAPACITY
#define CAPACITY 50
#endif

struct queue {
    int items[CAPACITY];
    unsigned int size;
    int front;
    int back;
};

/* queue_create() = <>
 */
struct queue* queue_create(){
    struct queue* q = malloc(sizeof(struct queue));
    assert(q != NULL && "Queue creation was not successful");
    q->size = 0;
    q->front = -1;
    q->back = -1;

    return q;
}

/* queue_is_empty(q) = true,   if q is empty
 *                   = false,  if q is not empty.
 */
bool queue_is_empty(struct queue* q){
    return q->front == -1;
}

/* queue_push(q, x):
 *
 * Pre-condition:  q = <x_0,...,x_{n-1}>
 * Post-condition:  q = <x_0,...,x_{n-1},x>.
 *
 * I.e., queue_push(q, x) puts x at the end of the queue q.
 */
void queue_push(struct queue* q, int x) {
    assert((q->back + 1) % CAPACITY != q->front && "Queue is full");
    q->back = (q->back + 1) % CAPACITY;
    q->items[q->back] = x;

    if (q->front == -1) {
        // Queue is empty, change front
        q->front = q->back;
    }

    q->size += 1;
}

/* queue_pop(q) = x; see pre/post-conditions.
 *
 * Pre-condition:  q = <x, x_0,...,x_{n-1}>, queue_is_empty(q) = false.
 * Post-condition:  q = <x_0,...,x_{n-1}>.
 *
 * I.e., queue_pop(q) returns the item at the front of q and removes it 
 * from q.
 *
 */
int queue_pop(struct queue* q) {
     assert(!queue_is_empty(q) && "Queue is empty");

    int x = q->items[q->front];

    q->front = (q->front + 1) % CAPACITY;
    q->size--;

    if (q->size == 0) {
        q->front = -1;
        q->back = -1;
    }

    return x;
}

/* queue_free(q):  free all resources associated to q that were dynamically
 * allocated.
 */
void queue_free(struct queue* q) {
    free(q);
}
/* queue_print(q):
 *
 * Post-condition:  information about q will be printed to the terminal.
 *
 * You may implement this function however you like.  It will not be used
 * during testing or examined.  But if you write it to print out information
 * about the concrete value q, then you can use it while debugging to see how
 * the concrete value is changing.
 */
void queue_print(struct queue* q) {
    int i ;
    for (i=0; i<q->size; i+=1) {
        printf("%s", i == q->size ? "|||" : "   ") ;
        printf("%d", q->items[i]) ;
    }
    if (q->size == CAPACITY) printf("|||") ;
    printf("\n") ;
}