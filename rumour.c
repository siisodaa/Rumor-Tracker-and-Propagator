#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "queue.h"

#define MAX_GUESTS 100
#define MAX_TRIALS 1000

/* 
spread(struct queue*, bool [], int, int)
chooses a spreader, and spreads the rumor to the rest of the guests until all the chosen guests heard the rumor
returns the the number of who heard the rumor over the total guests
*/
double spread(struct queue* spreaders, bool has_heard[], int n_guests, int times_to_spread, int n_heard){
    while (!queue_is_empty(spreaders)) {

        int p = queue_pop(spreaders);
        int j = lrand48() % n_guests;

        for(int i = 0; i < j; i++){
            int next = lrand48() % times_to_spread;

            if(next != p && has_heard[next] == false){
                queue_push(spreaders, next);
                has_heard[next] = true;
                n_heard += 1;
            }

        }
    }
    queue_free(spreaders);
    return n_heard/(double)n_guests;
}

/*
run_simulation(int, int)

creates the spreaders collection and creates an empty array for those who heard the rumor.
chooses the spreaders and calls on spread function to spread the rumor

returns spread function
*/
double run_simulation(int n_guests, int times_to_spread){
    bool has_heard[n_guests] ;

    for (int i = 0; i < n_guests; i++) {
        has_heard[i] = false;
    }

    struct queue* spreaders = queue_create();

    int n_heard = 1 ;

    has_heard[0] = true ;
    
    queue_push(spreaders, 0);

    return spread(spreaders, has_heard, n_guests,times_to_spread,n_heard);
}

/*
main_run(int, int, int)
Loops through the number of trials specified by the user and runs the simulation that many times
returns the combined average percentage of those who heard the rumor in the entire sumilations.
*/
double main_run(int n_guests, int n_trials, int times_to_spread){
    double total_prob = 0.0 ;

    for (int i=0; i<n_trials; i+=1) total_prob += run_simulation(n_guests, times_to_spread) ;

    return total_prob/n_trials ;
}
int main(void) {

    /* The maximum number of guests for which to compute the propagation ratio.
     */
    int     max_guests ;

    /* The number of trials.
     */
    int     n_trials ;

    int     times_to_spread ;

    /* Initialize the random number generator.
     */
    srand48(time(NULL)) ;

    printf("Maximum number of guests: ") ;
    scanf("%d", &max_guests) ;

    printf("Maximum spread: ") ;
    scanf("%d", &times_to_spread) ;

    printf("How many trials for each number of guests: ") ;
    scanf("%d", &n_trials) ;

    for (int i=2; i<=max_guests; i+=1) {
        printf("Average percentage of %d guests who heard the rumour:  %lf.\n",
                i, main_run(i, n_trials, times_to_spread)) ;
    }

    return 0 ;

}