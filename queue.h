/* COMP 211 Homework 7:  a queue abstract type.
 *
 * A value of type queue represents an ordered collection of int values.  We
 * write a typical such value <x_0,...,x_{n-1}>, where x_0 is the front of the
 * queue and x_{n-1} is the rear of the queue.  The only operations permitted
 * are to add an item at the rear and remove the item at the front.
 *
 * A queue may have at most CAPACITY-1 items.
 *
 * N. Danner
 */

#include <stdbool.h>

#ifndef CAPACITY
#define CAPACITY 10
#endif

/* The following line says that somebody (presumably an implementation file)
 * will actually define struct queue.
 *
 * DO NOT WRITE A DEFINITION OF struct queue HERE!  PUT YOUR DEFINITION IN
 * arrayqueue.c!  Remember, you will not submit this file; you will only submit
 * arrayqueue.c.
 */
struct queue ;

/* queue_create() = <>
 */
struct queue* queue_create() ;

/* queue_is_empty(q) = true,   if q is empty
 *                   = false,  if q is not empty.
 */
bool queue_is_empty(struct queue*) ;

/*  queue_push(q, x):
 *
 *  Pre-condition:  q = <x_0,...,x_{n-1}>
 *  Post-condition:  q = <x_0,...,x_{n-1},x>.
 *
 *  I.e., queue_push(q, x) puts x at the end of the queue q.
 */
void queue_push(struct queue*, int) ;

/*  queue_pop(q) = x; see pre/post-conditions.
 *
 *  Pre-condition:  q = <x, x_0,...,x_{n-1}>, queue_is_empty(q) = false.
 *  Post-condition:  q = <x_0,...,x_{n-1}>.
 *
 *  I.e., queue_pop(q) returns the item at the front of q and removes it 
 *  from q.
 *
 */
int queue_pop(struct queue*) ;

/*  queue_free(q):  free all resources associated to q that were dynamically
 *  allocated.
 */
void queue_free(struct queue*) ;

/* queue_print(q):
 *
 * Post-condition:  information about q will be printed to the terminal.
 *
 * You may implement this function however you like.  It will not be used
 * during testing or examined.  But if you write it to print out information
 * about the concrete value q, then you can use it while debugging to see how
 * the concrete value is changing.
 */
void queue_print(struct queue*) ;
