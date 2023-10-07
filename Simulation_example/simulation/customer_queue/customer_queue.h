#ifndef CUSTOMER_QUEUE_H
#define CUSTOMER_QUEUE_H

#define QUEUE_FULL -1
#define QUEUE_EMPTY -2
#define OK 0

typedef struct customer *Customer;

/**
 * add_customer_q: add a customer to the customer queue
 * 
 * time_arrived- The customers arrival time.
 * 
 * Return: OK if addition was succesful. Queue_FULL
 *          if queue is full.
*/
int add_customer_q(int time_arrived);

/**
 * del_customer: removes a customer from customer queue, and
 *               extract the customers transaction time and arrival time.
 * 
 * *tran_time- A pointer to the time of the customers transaction.
 * *arrival_time- A pointer to the customers arrival time.
 * 
 * Return: OK if operation was succesful.
*/
int del_customer_q(int *trans_time, int *arrival_time);

/**
 * queue_empty: Checks if queue is empty.
 * 
 * Return- OK if queue is not empty,
 *          QUEUE_EMPTY if queue is empty.
*/
int queue_empty();

#endif