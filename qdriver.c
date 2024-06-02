/* COMP 211 Homework 10:  Sets, dictionaries, and their implementations.
 *
 * This program maintains a dictionary that keeps track of how many times a
 * word is typed at the terminal.
 *
 * N. Danner
 */

#include <stdio.h>
#include <string.h>

#include "queue.h"

int main(void) {

    struct queue* q = queue_create() ;

    int choice ;

    do {
        printf(
            "\n"
            "(0) Exit.\n"
            "(1) Test empty.\n"
            "(2) Push key.\n"
            "(3) Pop.\n"
            "(4) Print queue.\n"
        ) ;
        printf("Enter choice: ") ;
        scanf("%d", &choice) ;

        switch (choice) {
            case 1:
                printf("Queue is%s empty.\n", 
                    queue_is_empty(q) ? "" : " not") ;
                break ;

            case 2:
            {
                int key ;
                printf("Enter key to push: ") ;
                scanf("%d", &key) ;
                queue_push(q, key) ;
                break ;
            }

            case 3:
            {
                int head = queue_pop(q) ;
                printf("Popped %d from queue.\n", head) ;
                break ;
            }

            case 4:
                queue_print(q) ;
                break ;

            case 0:
                break ;

            default:
                printf("Invalid choice!\n") ;
                break ;
        }

    } while (choice != 0) ;

    queue_free(q) ;

}