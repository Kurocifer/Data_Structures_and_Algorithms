#ifndef CUSTOMER_QUEUE_H
#define CUSTOMER_QUEUE_H

#define QUEUE_FULL -100
#define OK 0

int add_customer_q(int time_arrived);
int del_customer_q(struct customer *p);
int queue_empty();

#endif