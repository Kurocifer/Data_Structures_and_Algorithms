#ifndef CUSTOMER_QUEUE_H
#define CUSTOMER_QUEUE_H

#define QUEUE_FULL -1
#define QUEUE_EMPTY -2
#define OK 0

typedef struct customer *Customer;

int add_customer_q(int time_arrived);
int del_customer_q(int *trans_time, int *arrival_time);
int queue_empty();

#endif