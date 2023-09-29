/* simulatoin routines */
#include <stdlib.h>
#include <stdio.h>
#include "../customer_queue/customer_queue.h"

#define CLK_INCR 1       /* # Minutes in each loop */
#define MAX_TELLERS 10  /* Max # of tellers*/

struct tellers {
    int num_customers;  /* Number of customers */
    int trans_time;    /* Trans complete time */
}teller[MAX_TELLERS];

int open = 1;
int clock = 0;
float tot_customers;
float tot_wait;

int arrive(int minute, int customer)
{
    if((float)customer / (float)minute > ((float)rand() / 32767.0))
        return 1;

    return 0;
}

void accum(int now, int time_arrived)
{
    tot_customers += 1.0;
    tot_wait += ((float)now - (float)time_arrived);
}

void print_totals()
{
    printf("%.0f customer%s waited an average of %.2f minutes\n",
            tot_customers, tot_customers > 1 ? "s" : "", tot_wait / tot_customers);
    
}

int simulate(int close, int num_tellers, int num_customers)
{
    int i;
    int trans_duration_time, time_arrived;

    while(1) {
        if(clock >= close)      /* Time to close */
            open = 0;

        if(open == 1 && arrive(close, num_customers)) {
            /* New customer */
            if(add_customer_q(clock) == QUEUE_FULL)
                printf("\nQueue full\n");
            
        }

        /*process tellers and customers */
        for(i = 0; i < num_tellers; i++) {

            /* check if tellers current transaction is done */
            if(clock >= teller[i].trans_time)
                teller[i].trans_time = 0;
            
            /* Get next customer */
            if(teller[i].trans_time == 0 && !queue_empty()) {
                del_customer_q(&trans_duration_time, &time_arrived);
                teller[i].num_customers += 1;
                teller[i].trans_time = clock + trans_duration_time;
                accum(clock, time_arrived);
            }
        }

        if(queue_empty() && (open == 0)) {
            print_totals();
            return OK;
        }

        clock += CLK_INCR;
    } 
}